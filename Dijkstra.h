#pragma once
#include <iostream>
#include <map>
#include <set>
#include <stack>
using namespace std;
#include "Graph.h"
#include "ShortestPathCalculatable.h"
#include "DataLoader.h"

#define NULLNODE Node(0, "NULL")

/**
 * @ClassName Dijkstra
 * @brief 用于进行Dijkstra算法来计算两点之间最短路径的类
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */

class ShortestPathData;

class Dijkstra : public ShortestPathCalculatable
{
public:
	Graph schoolGraph; // 记载学校地图的Graph类

    /**
     * @brief 构造函数，用于将初始化学校的地图信息，学校的地图
     *        信息见文档
     */
	Dijkstra();

    /**
     * @brief 析构函数
     */
    ~Dijkstra();

    /**
     * @brief 计算最短路径
     * @param startingPoint 起点
     * @param terminal 终点
     * @return 返回最短路径的距离
     */
    void calculateShortestPath(Node startingPoint, Node terminal);

    /**
     * @brief 通过节点名称在图内查询对应节点
     * @param name 给定的节点名称
     * @return 返回查询到的指定的节点对象,未找到时，返回Node(0, "NULL")
     */
    Node getNode(string name);

private:
    /**
     * @brief 将学校的地图信息装载到schoolGraph变量中
     */
    void generateGraph();

	/**
	 * @brief 计算给定节点到其他节点的最短路径
	 * @brief 为初版实现，使用的是传统dijkstra算法的实现，效率较低
	 * @param node 给定的节点
	 * @return 返回最短路径的距离
	 */
	ShortestPathData dijkstra1(Node node);

	/**
	 * @brief 计算给定节点到其他节点的最短路径
	 * @brief 用改写堆的方式来优化，效率较高
	 * @param node 给定的节点
	 * @param size 节点的规模
	 * @return 返回最短路径的距离
	 */
	ShortestPathData dijkstra2(Node node, int size);

    /**
     * @brief 辅助函数，得到当前最小距离表中与起点距离最小且尚未被选择的节点
     * @param distanceMap 记录每个节点与初始节点的目前最小距离的哈希表
     * @param touchedNodes 记录已经得到最小距离且被选择的节点
     * @return 返回表中与起点距离最小且尚未被选择的节点
     */
    Node getMinDistanceAndUnselectedNode(map<Node, int> distanceMap,
        set<Node> touchedNodes);
    
};

/**
 * @brief 辅助类，用于装载使用dijkstra算法求解得到的数据
 */
class ShortestPathData {
public:
	map<Node, int> distanceMap; // 离起点最短的距离
	map<Node, Node> pathMap; // 最短路径上的前驱节点

	ShortestPathData() {}

	ShortestPathData(map<Node, int> distanceMap, map<Node, Node> pathMap) {
		this->distanceMap = distanceMap;
		this->pathMap = pathMap;
	}

	~ShortestPathData() {}
};

/**
 * @brief 辅助内部类，只作用在NodeHeap内部
 *		  用于打包Node和distance数据
 */
class NodeRecord {
public:
	Node node;
	int distance;

	NodeRecord() {}

	NodeRecord(Node node, int distance) {
		this->node = node;
		this->distance = distance;
	}
};

/**
 * @brief 辅助类，通过改写堆来对Dijkstra算法进行优化
 * @brief 核心思想是将记录节点路径长度的表用堆来存储，
 * @brief 但使用系统提供的堆结构存在问题是当一个处理一个节点时，
 * @brief 其关联的边连接的点对应的最短数据都会动态改变，系统提供的堆采取的是全局扫描的方式，
 * @brief 时间复杂度为O(n^2),与遍历的方式相比并没有优化，从而采用改写堆的方式来解决
 * @brief 使得时间复杂度能降低到O(nlogn)
 */
class NodeHeap {
private:
	Node* nodes; // 存储节点的数组
	map<Node, int> heapIndexMap; // 存储节点和对应数组下标的表
	map<Node, int> distanceMap; // 存储节点与对应当前最短路径
	int size; // 当前节点数组的规模

public:
	/**
	 * @brief 内部类的构造函数，初始化内部类的字段
	 * @param size 初始化节点数组的最大规模
	 */
	NodeHeap(int size) {
		nodes = new Node[size];
		this->size = 0;
	}

	/**
	 * @brief 判断点集是否为空
	 * @return 为空，返回1，否则返回0
	 */
	bool isEmpty() {
		return size == 0;
	}

	/**
	 * @brief 将一个点加入堆中，同时调整位置，更新对应的数据
	 * @param node 待加入的节点
	 * @param prevNode 引出待加入节点的前驱节点
	 * @param distance 待加入节点的当前距离
	 * @param pathMap 记录前驱节点的表
	 */
	void addOrUpdateOrIgnore(Node node, Node prevNode, int distance, map<Node, Node> &pathMap) {
		if (inHeap(node)) {
			int curr = distance;
			int prev = distanceMap.find(node)->second;
			if (curr < prev) {
				distanceMap.find(node)->second = curr;
				pathMap.find(node)->second = prevNode;
			}
			insertHeapify(node, heapIndexMap.find(node)->second);
		}
		if (!isEntered(node)) {
			nodes[size] = node;
			heapIndexMap.insert(make_pair(node, size));
			distanceMap.insert(make_pair(node, distance));
			pathMap.insert(make_pair(node, prevNode));
			insertHeapify(node, size++);
		}
	}

	/**
	 * @brief 弹出堆顶节点，由于采用了堆结构，该节点一定是当前状况下最短路径节点
	 * @return 返回堆顶节点的节点对象以及对应的最短距离
	 */
	NodeRecord pop() {
		NodeRecord nodeRecord(nodes[0], distanceMap.find(nodes[0])->second);
		swap(0, size - 1);
		heapIndexMap.find(nodes[size - 1])->second = -1;
		distanceMap.erase(nodes[size - 1]);
		nodes[size - 1] = NULLNODE;
		heapify(0, --size);
		return nodeRecord;
	}

private:
	/**
	 * @brief 插入上移操作，将指定节点插入堆中，并调整到适当位置
	 * @param node 待插入的节点
	 * @param index 待插入节点在节点数组中的下标
	 */
	void insertHeapify(Node node, int index) {
		while (distanceMap.find(nodes[index])->second < distanceMap.find(nodes[(index - 1) / 2])->second) {
			swap(index, (index - 1) / 2);
			index = (index - 1) / 2;
		}
	}

	/**
	 * @brief 插入下移操作，将堆中的节点下移到指定位置
	 * @param index 待调整的节点位置
	 * @param size 堆的当前大小，用于检测是否下移到最后一层
	 */
	void heapify(int index, int size) {
		int left = index << 1 + 1;
		while (left < size) {
			int smallest = left + 1 < size &&
				distanceMap.find(nodes[left + 1])->second < distanceMap.find(nodes[left])->second ? left + 1 : left;
			smallest = distanceMap.find(nodes[smallest])->second < distanceMap.find(nodes[index])->second ? smallest : index;
			if (smallest == index) {
				break;
			}
			swap(smallest, index);
			index = smallest;
			left = index << 2 + 1;
		}
	}

	/**
	 * @brief 检测节点是否已在堆中处理过
	 * @param node 待检测的节点 
	 * @return 处理过返回true,否则返回false
	 */
	bool isEntered(Node node) {
		return heapIndexMap.find(node) != heapIndexMap.end();
	}

	/**
	 * @brief 检测节点是否在堆中
	 * @param node 待检测的节点
	 * @return 已加入返回true,否则返回false
	 */
	bool inHeap(Node node) {
		return isEntered(node) && heapIndexMap.find(node)->second != -1;
	}

	/**
	 * @brief 交换堆中两个节点的位置，同时更新数据情况
	 * @param index1 待交换的节点1在数组中的下标
	 * @param index2 带交换的节点2在数组中的下标
	 */
	void swap(int index1, int index2) {
		heapIndexMap.find(nodes[index1])->second = index2;
		heapIndexMap.find(nodes[index2])->second = index1;
		Node temp = nodes[index1];
		nodes[index1] = nodes[index2];
		nodes[index2] = temp;
	}
};
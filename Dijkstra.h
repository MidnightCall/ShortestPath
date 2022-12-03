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
     * @brief 计算给定节点到其他节点的最短路径
     * @brief 用改写堆的方式来优化，效率较高
     * @param node 给定的节点
     * @param size 节点的规模
     * @return 返回最短路径的距离
     */
    map<Node, int> dijkstra2(Node node, int size);

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
	map<Node, int> distanceMap;
	map<Node, Node> pathMap;

	ShortestPathData() {}

	ShortestPathData(map<Node, int> distanceMap, map<Node, Node> pathMap) {
		this->distanceMap = distanceMap;
		this->pathMap = pathMap;
	}

	~ShortestPathData() {}
};

/**
 * @brief 辅助内部类，通过改写堆来对Dijkstra算法进行优化
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
 * @brief 核心思想是将记录节点路径长度的表用堆来存储
 * @brief 但存在问题是当一个处理一个节点时，其关联的
 * @brief 边连接的点对应的最短数据都会动态改变，若使
 * @brief 用系统提供的堆采取的是全局扫描的方式，效率
 * @brief 和直接查找相差不大，从而此处采取改写堆的方
 * @brief 来优化
 */
class NodeHeap {
private:
	Node* nodes;
	map<Node, int> heapIndexMap;
	map<Node, int> distanceMap;
	int size;

public:
	/**
	* @brief 内部类的构造函数，初始化内部类的字段
	* @param size 初始化点集数组的大小
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

	void addOrUpdateOrIgnore(Node node, int distance) {
		if (inHeap(node)) {
			distanceMap.find(node)->second = min(distanceMap.find(node)->second, distance);
			insertHeapify(node, heapIndexMap.find(node)->second);
		}
		if (!isEntered(node)) {
			nodes[size] = node;
			heapIndexMap.insert(make_pair(node, size));
			distanceMap.insert(make_pair(node, distance));
			insertHeapify(node, size++);
		}
	}

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
	void insertHeapify(Node node, int index) {
		while (distanceMap.find(nodes[index])->second < distanceMap.find(nodes[(index - 1) / 2])->second) {
			swap(index, (index - 1) / 2);
			index = (index - 1) / 2;
		}
	}

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

	bool isEntered(Node node) {
		return heapIndexMap.find(node) != heapIndexMap.end();
	}

	bool inHeap(Node node) {
		return isEntered(node) && heapIndexMap.find(node)->second != -1;
	}

	void swap(int index1, int index2) {
		heapIndexMap.find(nodes[index1])->second = index2;
		heapIndexMap.find(nodes[index2])->second = index1;
		Node temp = nodes[index1];
		nodes[index1] = nodes[index2];
		nodes[index2] = temp;
	}
};
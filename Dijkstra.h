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
 * @brief ���ڽ���Dijkstra�㷨����������֮�����·������
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */

class ShortestPathData;

class Dijkstra : public ShortestPathCalculatable
{
public:
	Graph schoolGraph; // ����ѧУ��ͼ��Graph��

    /**
     * @brief ���캯�������ڽ���ʼ��ѧУ�ĵ�ͼ��Ϣ��ѧУ�ĵ�ͼ
     *        ��Ϣ���ĵ�
     */
	Dijkstra();

    /**
     * @brief ��������
     */
    ~Dijkstra();

    /**
     * @brief �������·��
     * @param startingPoint ���
     * @param terminal �յ�
     * @return �������·���ľ���
     */
    void calculateShortestPath(Node startingPoint, Node terminal);

    

    /**
     * @brief ��������ڵ㵽�����ڵ�����·��
     * @brief �ø�д�ѵķ�ʽ���Ż���Ч�ʽϸ�
     * @param node �����Ľڵ�
     * @param size �ڵ�Ĺ�ģ
     * @return �������·���ľ���
     */
    map<Node, int> dijkstra2(Node node, int size);

    /**
     * @brief ͨ���ڵ�������ͼ�ڲ�ѯ��Ӧ�ڵ�
     * @param name �����Ľڵ�����
     * @return ���ز�ѯ����ָ���Ľڵ����,δ�ҵ�ʱ������Node(0, "NULL")
     */
    Node getNode(string name);

private:
    /**
     * @brief ��ѧУ�ĵ�ͼ��Ϣװ�ص�schoolGraph������
     */
    void generateGraph();

	/**
	 * @brief ��������ڵ㵽�����ڵ�����·��
	 * @brief Ϊ����ʵ�֣�ʹ�õ��Ǵ�ͳdijkstra�㷨��ʵ�֣�Ч�ʽϵ�
	 * @param node �����Ľڵ�
	 * @return �������·���ľ���
	 */
	ShortestPathData dijkstra1(Node node);

    /**
     * @brief �����������õ���ǰ��С�����������������С����δ��ѡ��Ľڵ�
     * @param distanceMap ��¼ÿ���ڵ����ʼ�ڵ��Ŀǰ��С����Ĺ�ϣ��
     * @param touchedNodes ��¼�Ѿ��õ���С�����ұ�ѡ��Ľڵ�
     * @return ���ر�������������С����δ��ѡ��Ľڵ�
     */
    Node getMinDistanceAndUnselectedNode(map<Node, int> distanceMap,
        set<Node> touchedNodes);
    
};

/**
 * @brief �����࣬����װ��ʹ��dijkstra�㷨���õ�������
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
 * @brief �����ڲ��࣬ͨ����д������Dijkstra�㷨�����Ż�
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
 * @brief �����࣬ͨ����д������Dijkstra�㷨�����Ż�
 * @brief ����˼���ǽ���¼�ڵ�·�����ȵı��ö����洢
 * @brief �����������ǵ�һ������һ���ڵ�ʱ���������
 * @brief �����ӵĵ��Ӧ��������ݶ��ᶯ̬�ı䣬��ʹ
 * @brief ��ϵͳ�ṩ�ĶѲ�ȡ����ȫ��ɨ��ķ�ʽ��Ч��
 * @brief ��ֱ�Ӳ������󣬴Ӷ��˴���ȡ��д�ѵķ�
 * @brief ���Ż�
 */
class NodeHeap {
private:
	Node* nodes;
	map<Node, int> heapIndexMap;
	map<Node, int> distanceMap;
	int size;

public:
	/**
	* @brief �ڲ���Ĺ��캯������ʼ���ڲ�����ֶ�
	* @param size ��ʼ���㼯����Ĵ�С
	*/
	NodeHeap(int size) {
		nodes = new Node[size];
		this->size = 0;
	}

	/**
	* @brief �жϵ㼯�Ƿ�Ϊ��
	* @return Ϊ�գ�����1�����򷵻�0
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
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
	 * @brief ��������ڵ㵽�����ڵ�����·��
	 * @brief �ø�д�ѵķ�ʽ���Ż���Ч�ʽϸ�
	 * @param node �����Ľڵ�
	 * @param size �ڵ�Ĺ�ģ
	 * @return �������·���ľ���
	 */
	ShortestPathData dijkstra2(Node node, int size);

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
	map<Node, int> distanceMap; // �������̵ľ���
	map<Node, Node> pathMap; // ���·���ϵ�ǰ���ڵ�

	ShortestPathData() {}

	ShortestPathData(map<Node, int> distanceMap, map<Node, Node> pathMap) {
		this->distanceMap = distanceMap;
		this->pathMap = pathMap;
	}

	~ShortestPathData() {}
};

/**
 * @brief �����ڲ��ֻ࣬������NodeHeap�ڲ�
 *		  ���ڴ��Node��distance����
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
 * @brief ����˼���ǽ���¼�ڵ�·�����ȵı��ö����洢��
 * @brief ��ʹ��ϵͳ�ṩ�Ķѽṹ���������ǵ�һ������һ���ڵ�ʱ��
 * @brief ������ı����ӵĵ��Ӧ��������ݶ��ᶯ̬�ı䣬ϵͳ�ṩ�ĶѲ�ȡ����ȫ��ɨ��ķ�ʽ��
 * @brief ʱ�临�Ӷ�ΪO(n^2),������ķ�ʽ��Ȳ�û���Ż����Ӷ����ø�д�ѵķ�ʽ�����
 * @brief ʹ��ʱ�临�Ӷ��ܽ��͵�O(nlogn)
 */
class NodeHeap {
private:
	Node* nodes; // �洢�ڵ������
	map<Node, int> heapIndexMap; // �洢�ڵ�Ͷ�Ӧ�����±�ı�
	map<Node, int> distanceMap; // �洢�ڵ����Ӧ��ǰ���·��
	int size; // ��ǰ�ڵ�����Ĺ�ģ

public:
	/**
	 * @brief �ڲ���Ĺ��캯������ʼ���ڲ�����ֶ�
	 * @param size ��ʼ���ڵ����������ģ
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

	/**
	 * @brief ��һ���������У�ͬʱ����λ�ã����¶�Ӧ������
	 * @param node ������Ľڵ�
	 * @param prevNode ����������ڵ��ǰ���ڵ�
	 * @param distance ������ڵ�ĵ�ǰ����
	 * @param pathMap ��¼ǰ���ڵ�ı�
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
	 * @brief �����Ѷ��ڵ㣬���ڲ����˶ѽṹ���ýڵ�һ���ǵ�ǰ״�������·���ڵ�
	 * @return ���ضѶ��ڵ�Ľڵ�����Լ���Ӧ����̾���
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
	 * @brief �������Ʋ�������ָ���ڵ������У����������ʵ�λ��
	 * @param node ������Ľڵ�
	 * @param index ������ڵ��ڽڵ������е��±�
	 */
	void insertHeapify(Node node, int index) {
		while (distanceMap.find(nodes[index])->second < distanceMap.find(nodes[(index - 1) / 2])->second) {
			swap(index, (index - 1) / 2);
			index = (index - 1) / 2;
		}
	}

	/**
	 * @brief �������Ʋ����������еĽڵ����Ƶ�ָ��λ��
	 * @param index �������Ľڵ�λ��
	 * @param size �ѵĵ�ǰ��С�����ڼ���Ƿ����Ƶ����һ��
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
	 * @brief ���ڵ��Ƿ����ڶ��д����
	 * @param node �����Ľڵ� 
	 * @return ���������true,���򷵻�false
	 */
	bool isEntered(Node node) {
		return heapIndexMap.find(node) != heapIndexMap.end();
	}

	/**
	 * @brief ���ڵ��Ƿ��ڶ���
	 * @param node �����Ľڵ�
	 * @return �Ѽ��뷵��true,���򷵻�false
	 */
	bool inHeap(Node node) {
		return isEntered(node) && heapIndexMap.find(node)->second != -1;
	}

	/**
	 * @brief �������������ڵ��λ�ã�ͬʱ�����������
	 * @param index1 �������Ľڵ�1�������е��±�
	 * @param index2 �������Ľڵ�2�������е��±�
	 */
	void swap(int index1, int index2) {
		heapIndexMap.find(nodes[index1])->second = index2;
		heapIndexMap.find(nodes[index2])->second = index1;
		Node temp = nodes[index1];
		nodes[index1] = nodes[index2];
		nodes[index2] = temp;
	}
};
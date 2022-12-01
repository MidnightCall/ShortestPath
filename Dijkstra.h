#pragma once
#include <iostream>
#include <map>
#include <set>
using namespace std;
#include "Graph.h"
#include "ShortestPathCalculatable.h"
#include "DataLoader.h"

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
     * @brief �������·��
     * @param startingPoint ���
     * @param terminal �յ�
     * @return �������·���ľ���
     */
    int calculateShortestPath(Node startingPoint, Node terminal);

    /**
     * @brief ��������ڵ㵽�����ڵ�����·��
     * @brief Ϊ����ʵ�֣�ʹ�õ��Ǵ�ͳdijkstra�㷨��ʵ�֣�Ч�ʽϵ�
     * @param node �����Ľڵ�
     * @return �������·���ľ���
     */
    map<Node, int> dijkstra1(Node node);

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
     * @brief �ø�д�ѵķ�ʽ���Ż���Ч�ʽϸ�
     * @param node �����Ľڵ�
     * @param size �ڵ�Ĺ�ģ
     * @return �������·���ľ���
     */
    map<Node, int> dijkstra2(Node node, int size);

    /**
     * @brief �����������õ���ǰ��С�����������������С����δ��ѡ��Ľڵ�
     * @param distanceMap ��¼ÿ���ڵ����ʼ�ڵ��Ŀǰ��С����Ĺ�ϣ��
     * @param touchedNodes ��¼�Ѿ��õ���С�����ұ�ѡ��Ľڵ�
     * @return ���ر�������������С����δ��ѡ��Ľڵ�
     */
    Node getMinDistanceAndUnselectedNode(map<Node, int> distanceMap,
        set<Node> touchedNodes);

    /**
     * @brief �����ڲ��࣬����װ��ʹ��dijkstra�㷨���õ�������
     */
    class shortestPathData;

    /**
     * @brief �����ڲ��࣬ͨ����д������Dijkstra�㷨�����Ż�
     */
    class NodeRecord;

    /**
     * @brief �����ڲ��࣬ͨ����д������Dijkstra�㷨�����Ż�
     */
    class NodeHeap {
    private:
        Node node;
        map<Node, int> heapIndexMap;
        map<Node, int> distaceMap;
        int size;

    public:
        /**
            * @brief �ڲ���Ĺ��캯������ʼ���ڲ�����ֶ�
            * @param size ��ʼ���㼯����Ĵ�С
            */
        NodeHeap(int size);

        /**
            * @brief �жϵ㼯�Ƿ�Ϊ��
            * @return Ϊ�գ�����1�����򷵻�0
            */
        bool isEmpty();

        void addOrUpdateOrIgnore(Node node, int distance);

        NodeRecord pop();
    };
};


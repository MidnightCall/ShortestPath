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
	Graph schoolGraph; // 记载学校地图的Graph类

    /**
     * @brief 构造函数，用于将初始化学校的地图信息，学校的地图
     *        信息见文档
     */
	Dijkstra();

    /**
     * @brief 计算最短路径
     * @param startingPoint 起点
     * @param terminal 终点
     * @return 返回最短路径的距离
     */
    int calculateShortestPath(Node startingPoint, Node terminal);

    /**
     * @brief 计算给定节点到其他节点的最短路径
     * @brief 为初版实现，使用的是传统dijkstra算法的实现，效率较低
     * @param node 给定的节点
     * @return 返回最短路径的距离
     */
    map<Node, int> dijkstra1(Node node);

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
     * @brief 用改写堆的方式来优化，效率较高
     * @param node 给定的节点
     * @param size 节点的规模
     * @return 返回最短路径的距离
     */
    map<Node, int> dijkstra2(Node node, int size);

    /**
     * @brief 辅助函数，得到当前最小距离表中与起点距离最小且尚未被选择的节点
     * @param distanceMap 记录每个节点与初始节点的目前最小距离的哈希表
     * @param touchedNodes 记录已经得到最小距离且被选择的节点
     * @return 返回表中与起点距离最小且尚未被选择的节点
     */
    Node getMinDistanceAndUnselectedNode(map<Node, int> distanceMap,
        set<Node> touchedNodes);

    /**
     * @brief 辅助内部类，用于装载使用dijkstra算法求解得到的数据
     */
    class shortestPathData;

    /**
     * @brief 辅助内部类，通过改写堆来对Dijkstra算法进行优化
     */
    class NodeRecord;

    /**
     * @brief 辅助内部类，通过改写堆来对Dijkstra算法进行优化
     */
    class NodeHeap {
    private:
        Node node;
        map<Node, int> heapIndexMap;
        map<Node, int> distaceMap;
        int size;

    public:
        /**
            * @brief 内部类的构造函数，初始化内部类的字段
            * @param size 初始化点集数组的大小
            */
        NodeHeap(int size);

        /**
            * @brief 判断点集是否为空
            * @return 为空，返回1，否则返回0
            */
        bool isEmpty();

        void addOrUpdateOrIgnore(Node node, int distance);

        NodeRecord pop();
    };
};


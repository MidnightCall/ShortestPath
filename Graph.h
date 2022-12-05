#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Node;
class Edge;

/**
 * @ClassName Graph
 * @brief 核心数据结构，用于表示图的类，包含点集和边集两个字段
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:30
 * @brief Version: beta-1.0
 */
class Graph
{
public:
	map<int, Node> nodes; // 图包含的点集
	set<Edge> edges; // 图包含的边集

	/**
	 * @brief 空参构造器
	 */
	Graph();
};

/**
 * @ClassName Node
 * @brief 表示图内节点的类，包含点度、入度、出度以及节点名称的字段
 *		  此外还包含与该点相关联的点和边的集合 
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:35
 * @brief Version: beta-1.0
 */
class Node
{
public:
	string name; // 对应的地点名称

	vector<Edge> edges; // 相关联的边的集合

	// 运算符重载
	bool operator==(const Node& other) const;

	bool operator!=(const Node& other) const;

	bool operator<(const Node& other) const;

	// 默认构造函数
	Node();

	// 初始化名称构造器
	Node(string name);

};

/**
 * @ClassName Edge
 * @brief 用于表示图中边的数据结构，包含边的权重，入点、出点三个字段
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 13:37
 * @brief Version: beta-1.0
 */

class Edge
{
public:
	int weight; // 边的权重
	Node* from; // 入点
	Node* to; // 出点
	
	// 重载<运算符
	bool operator<(const Edge& other) const;

	// 默认构造函数
	Edge();

	// 初始化边权重，出点，入点的构造函数
	Edge(int weight, Node *from, Node *to);

};

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
 * @brief Date: 2022/11/30 12:14
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

	/**
	 * @brief 析构函数
	 */
	~Graph();
};

/**
 * @ClassName Node
 * @brief 表示图内节点的类，包含点度、入度、出度以及节点名称的字段
 *		  此外还包含与该点相关联的点和边的集合 
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */
class Node
{
public:
	int value; // 点度
	int in; // 入度
	int out; // 出度
	string name; // 对应的地点名称

	vector<Node> nexts; // 相关联的点的集合
	vector<Edge> edges; // 相关联的边的集合

	// 重载==运算符
	bool operator==(const Node& other) const;

	// 重载!=运算符
	bool operator!=(const Node& other) const;

	// 重载<运算符
	bool operator<(const Node& other) const;

	// 默认构造函数
	Node();

	// 初始化点度构造器
	Node(int value, string name);

	// 初始化点度、入度、出度构造器
	Node(int value, int in, int out, string name);
};

/**
 * @ClassName Edge
 * @brief 用于表示图中边的数据结构，包含边的权重，入点、出点三个字段
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
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

	// 析构函数，回收分配在堆上的from和to对象
	~Edge();
};

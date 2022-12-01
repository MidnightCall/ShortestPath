#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Node;
class Edge;

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

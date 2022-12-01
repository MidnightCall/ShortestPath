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
	map<int, Node> nodes; // ͼ�����ĵ㼯
	set<Edge> edges; // ͼ�����ı߼�

	/**
	 * @brief �ղι�����
	 */
	Graph();

	/**
	 * @brief ��������
	 */
	~Graph();
};

class Node
{
public:
	int value; // ���
	int in; // ���
	int out; // ����
	string name; // ��Ӧ�ĵص�����

	vector<Node> nexts; // ������ĵ�ļ���
	vector<Edge> edges; // ������ıߵļ���

	// ����==�����
	bool operator==(const Node& other) const;

	// ����!=�����
	bool operator!=(const Node& other) const;

	// ����<�����
	bool operator<(const Node& other) const;

	// Ĭ�Ϲ��캯��
	Node();

	// ��ʼ����ȹ�����
	Node(int value, string name);

	// ��ʼ����ȡ���ȡ����ȹ�����
	Node(int value, int in, int out, string name);
};

class Edge
{
public:
	int weight; // �ߵ�Ȩ��
	Node* from; // ���
	Node* to; // ����
	
	// ����<�����
	bool operator<(const Edge& other) const;

	// Ĭ�Ϲ��캯��
	Edge();

	// ��ʼ����Ȩ�أ����㣬���Ĺ��캯��
	Edge(int weight, Node *from, Node *to);
};

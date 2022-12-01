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
 * @brief �������ݽṹ�����ڱ�ʾͼ���࣬�����㼯�ͱ߼������ֶ�
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */
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

/**
 * @ClassName Node
 * @brief ��ʾͼ�ڽڵ���࣬������ȡ���ȡ������Լ��ڵ����Ƶ��ֶ�
 *		  ���⻹������õ�������ĵ�ͱߵļ��� 
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */
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

/**
 * @ClassName Edge
 * @brief ���ڱ�ʾͼ�бߵ����ݽṹ�������ߵ�Ȩ�أ���㡢���������ֶ�
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */

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

	// �������������շ����ڶ��ϵ�from��to����
	~Edge();
};
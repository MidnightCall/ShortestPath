#include "Dijkstra.h"

//-----------------------constuctor implementation------------------------------
Dijkstra::Dijkstra() {
	generateGraph();
}

Dijkstra::~Dijkstra() {
	
}

//-------------------public function implementation-----------------------------
void Dijkstra::calculateShortestPath(Node startingPoint, Node terminal) {
	ShortestPathData data = dijkstra2(startingPoint, 5);
	stack<Node> path; // ���·��
	int shortestLength; // ���·������
	path.push(terminal);
	
	// ��¼���·������
	shortestLength = data.distanceMap.find(terminal)->second;

	// ��ǰ�������·��
	Node prevNode = data.pathMap.find(terminal)->second;
	while (prevNode != NULLNODE) {
		path.push(prevNode);
		prevNode = data.pathMap.find(prevNode)->second;
	}

	cout << "���·��Ϊ:";
	while (!path.empty()) {
		Node currNode = path.top();
		cout << currNode.name;
		path.pop();
		if (!path.empty()) {
			cout << "->";
		}
	}
	cout << endl;

	cout << "��·������Ϊ:" << shortestLength << endl;
}

Node Dijkstra::getNode(string name) {
	map<int, Node> nodes = schoolGraph.nodes;
	for (map<int, Node>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter) {
		if (iter->second.name == name) {
			return iter->second;
		}
	}
	return Node("NULL");
}

//-------------------private function implementation-----------------------------
void Dijkstra::generateGraph(){
	DataLoader loader;
	schoolGraph = loader.loadData();
}

ShortestPathData Dijkstra::dijkstra1(Node node) {
	map<Node, int> distanceMap; // ��¼ָ���ڵ㵽�������ڵ�ĵ�ǰ��̾���
	map<Node, Node> pathMap; // ��¼ÿ���ڵ����·����ǰ���ڵ�
	distanceMap.insert(make_pair(node, 0)); // ����ǰ�ڵ�����������ʼ��Ϊ0
	set<Node> selectedNodes; // ��¼�Ѿ��������С·���Ľڵ�

	Node minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
	pathMap.insert(make_pair(minNode, NULLNODE));
	while (minNode != NULLNODE) {
		int distance = distanceMap.find(minNode)->second;
		for (vector<Edge>::iterator iter = minNode.edges.begin(); iter != minNode.edges.end(); iter++) { 
			// ������ǰ·����̽ڵ�ĳ��ߣ����������·����
			Node* toNode = iter->to;
			if (distanceMap.find(*toNode) == distanceMap.end()) { // �����ڵĽڵ������
				distanceMap.insert(make_pair(*toNode, distance + iter->weight));// ��ӵ���̾������
				pathMap.insert(make_pair(*toNode, minNode)); // ����ǰ���ڵ�
			}
			// ���п��滻�����·�����滻
			int currLength = distance + iter->weight;
			int prevLength = distanceMap.find(*toNode)->second;
			if (currLength < prevLength) {
				distanceMap.find(*toNode)->second = currLength; // ����·������
				pathMap.find(*toNode)->second = minNode; // ����ǰ��·��
			}
		}
		selectedNodes.insert(minNode);// ������ϵĵ�ǰ�ڵ������ѡ��ڵ�ı���
		minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes); 
	}
	ShortestPathData data(distanceMap, pathMap); // �������ݴ��
	return data;
}

ShortestPathData Dijkstra::dijkstra2(Node node, int size) {
	NodeHeap nodeHeap(size);
	map<Node, int> distanceMap; // ��¼ָ���ڵ㵽�������ڵ�ĵ�ǰ��̾���
	map<Node, Node> pathMap; // ��¼ÿ���ڵ����·����ǰ���ڵ�
	pathMap.insert(make_pair(node, NULLNODE));
	nodeHeap.addOrUpdateOrIgnore(node, NULLNODE, 0, pathMap);
	while (!nodeHeap.isEmpty()) {
		NodeRecord record = nodeHeap.pop();
		Node curr = record.node;
		int distance = record.distance;
		for (vector<Edge>::iterator iter = curr.edges.begin(); iter != curr.edges.end(); ++iter) {
			nodeHeap.addOrUpdateOrIgnore(*(iter->to), curr, iter->weight + distance, pathMap);
		}
		distanceMap.insert(make_pair(curr, distance));
	}
	ShortestPathData data(distanceMap, pathMap);
	return data;
}

Node Dijkstra::getMinDistanceAndUnselectedNode(map<Node, int> distanceMap,
	set<Node> touchedNodes){
	Node minNode("NULL");
	int minDistance = INT_MAX;
	for (map<Node, int>::iterator iter = distanceMap.begin(); iter != distanceMap.end(); ++iter) {
		Node node = iter->first;
		int distance = iter->second;
		if (touchedNodes.find(node) == touchedNodes.end() && distance < minDistance) {
			minNode = node;
			minDistance = distance;
		}
	}
	return minNode;
}

#include "Dijkstra.h"

//-----------------------constuctor implementation------------------------------
Dijkstra::Dijkstra() {
	generateGraph();
}

//-------------------public function implementation-----------------------------
int Dijkstra::calculateShortestPath(Node startingPoint, Node terminal) {
	return 0;
}

Node Dijkstra::getNode(string name) {
	map<int, Node> nodes = schoolGraph.nodes;
	for (map<int, Node>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter) {
		if (iter->second.name == name) {
			return iter->second;
		}
	}
	return Node(0, "NULL");
}


//-------------------private function implementation-----------------------------
void Dijkstra::generateGraph(){
	DataLoader loader;
	schoolGraph = loader.loadData();
}

map<Node, int> Dijkstra::dijkstra1(Node node) {
	map<Node, int> distanceMap; // ��¼ָ���ڵ㵽�������ڵ�ĵ�ǰ��̾���
	distanceMap.insert(make_pair(node, 0)); // ����ǰ�ڵ�����������ʼ��Ϊ0
	set<Node> selectedNodes; // ��¼�Ѿ��������С·���Ľڵ�
	Node nullNode(0, "NULL");

	Node minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
	while (minNode != nullNode) {
		int distance = distanceMap.find(minNode)->second;
		for (vector<Edge>::iterator iter = minNode.edges.begin(); iter != minNode.edges.end(); iter++) {
			Node* toNode = iter->to;
			if (distanceMap.find(*toNode) == distanceMap.end()) {
				distanceMap.insert(make_pair(*toNode, distance + iter->weight));
			}
			/*
			int prev = distanceMap.find(*toNode)->second; // ��ǰ���·������
			int curr = distance + iter->weight; // �µ����·������
			*/
			distanceMap.find(*toNode)->second = min(distanceMap.find(*toNode)->second, distance + iter->weight);
			//distanceMap.insert(make_pair(*iter->to, min(distanceMap.find(*toNode)->second, distance + iter->weight)));
		}
		selectedNodes.insert(minNode);
		minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
		int i = 0;
	}
	return distanceMap;
}


Node Dijkstra::getMinDistanceAndUnselectedNode(map<Node, int> distanceMap,
	set<Node> touchedNodes){
	Node minNode(0, "NULL");
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

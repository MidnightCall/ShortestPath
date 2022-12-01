#include "Dijkstra.h"

//-----------------------constuctor implementation------------------------------
Dijkstra::Dijkstra() {
	generateGraph();
}

Dijkstra::~Dijkstra() {
	
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

ShortestPathData Dijkstra::dijkstra1(Node node) {
	map<Node, int> distanceMap; // 记录指定节点到其他各节点的当前最短距离
	distanceMap.insert(make_pair(node, 0)); // 将当前节点与自身距离初始化为0
	set<Node> selectedNodes; // 记录已经计算出最小路径的节点

	Node minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
	while (minNode != NULLNODE) {
		int distance = distanceMap.find(minNode)->second;
		for (vector<Edge>::iterator iter = minNode.edges.begin(); iter != minNode.edges.end(); iter++) { 
			// 遍历当前路径最短节点的出边，并更新最短路径表
			Node* toNode = iter->to;
			if (distanceMap.find(*toNode) == distanceMap.end()) { // 不存在的节点则添加
				distanceMap.insert(make_pair(*toNode, distance + iter->weight));
			}
			// 若有可替换的最短路径则替换
			distanceMap.find(*toNode)->second = min(distanceMap.find(*toNode)->second, distance + iter->weight);
		}
		selectedNodes.insert(minNode);// 处理完毕的当前节点加入已选择节点的表中
		minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes); 
	}
	return distanceMap;
}

map<Node, int> dijkstra2(Node node, int size) {
	
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

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
	stack<Node> path; // 最短路径
	int shortestLength; // 最短路径长度
	path.push(terminal);
	
	// 记录最短路径长度
	shortestLength = data.distanceMap.find(terminal)->second;

	// 向前查找最短路径
	Node prevNode = data.pathMap.find(terminal)->second;
	while (prevNode != NULLNODE) {
		path.push(prevNode);
		prevNode = data.pathMap.find(prevNode)->second;
	}

	cout << "最短路径为:";
	while (!path.empty()) {
		Node currNode = path.top();
		cout << currNode.name;
		path.pop();
		if (!path.empty()) {
			cout << "->";
		}
	}
	cout << endl;

	cout << "此路径长度为:" << shortestLength << endl;
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
	map<Node, int> distanceMap; // 记录指定节点到其他各节点的当前最短距离
	map<Node, Node> pathMap; // 记录每个节点最短路径的前驱节点
	distanceMap.insert(make_pair(node, 0)); // 将当前节点与自身距离初始化为0
	set<Node> selectedNodes; // 记录已经计算出最小路径的节点

	Node minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
	pathMap.insert(make_pair(minNode, NULLNODE));
	while (minNode != NULLNODE) {
		int distance = distanceMap.find(minNode)->second;
		for (vector<Edge>::iterator iter = minNode.edges.begin(); iter != minNode.edges.end(); iter++) { 
			// 遍历当前路径最短节点的出边，并更新最短路径表
			Node* toNode = iter->to;
			if (distanceMap.find(*toNode) == distanceMap.end()) { // 不存在的节点则添加
				distanceMap.insert(make_pair(*toNode, distance + iter->weight));// 添加到最短距离表中
				pathMap.insert(make_pair(*toNode, minNode)); // 更新前驱节点
			}
			// 若有可替换的最短路径则替换
			int currLength = distance + iter->weight;
			int prevLength = distanceMap.find(*toNode)->second;
			if (currLength < prevLength) {
				distanceMap.find(*toNode)->second = currLength; // 更新路径长度
				pathMap.find(*toNode)->second = minNode; // 更新前驱路径
			}
		}
		selectedNodes.insert(minNode);// 处理完毕的当前节点加入已选择节点的表中
		minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes); 
	}
	ShortestPathData data(distanceMap, pathMap); // 返回数据打包
	return data;
}

ShortestPathData Dijkstra::dijkstra2(Node node, int size) {
	NodeHeap nodeHeap(size);
	map<Node, int> distanceMap; // 记录指定节点到其他各节点的当前最短距离
	map<Node, Node> pathMap; // 记录每个节点最短路径的前驱节点
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

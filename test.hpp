#ifndef TEST_HPP_
#define TEST_HPP_

#include "Dijkstra.h"

class Test {
public:
	Dijkstra test;
	// pass
	void testDijkstra1() {
		test.calculateShortestPath(test.getNode("D"), test.getNode("B"));
	}

	void testDijkstra2() {
		map<Node, int> lengthMap = test.dijkstra2(test.getNode("A"), 5);
		for (map<Node, int>::iterator iter = lengthMap.begin(); iter != lengthMap.end(); ++iter) {
			cout << iter->first.name << " " << iter->second << endl;
		}
	}
};

#endif // !TEST_HPP_

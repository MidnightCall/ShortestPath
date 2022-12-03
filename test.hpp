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
		test.calculateShortestPath(test.getNode("D"), test.getNode("B"));
	}
};

#endif // !TEST_HPP_

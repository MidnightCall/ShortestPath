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

	// pass
	void testDijkstra2() {
		string start;
		string end;
		cout << "���������:" << endl;
		cin >> start;

		cout << "�������յ�:" << endl;
		cin >> end;

		test.calculateShortestPath(test.getNode(start), test.getNode(end));
	}
};

#endif // !TEST_HPP_

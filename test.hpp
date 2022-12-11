#ifndef TEST_HPP_
#define TEST_HPP_

#include "Dijkstra.h"

/**
 * @ClassName Test
 * @brief 测试用类，完成后废弃
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */
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
		cout << "请输入起点:" << endl;
		cin >> start;

		cout << "请输入终点:" << endl;
		cin >> end;

		test.calculateShortestPath(test.getNode(start), test.getNode(end));
	}
};

#endif // !TEST_HPP_

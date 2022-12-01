#include <iostream>
using namespace std;
#include "Dijkstra.h"

void test1() {
	Dijkstra d;
	d.calculateShortestPath(d.getNode("D"), d.getNode("B"));
}

int main(void){
	test1();

	system("pause");
	return 0;
}

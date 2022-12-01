#include <iostream>
using namespace std;
#include "Dijkstra.h"

void test1() {
	Dijkstra d;
	map<Node, int> shortestMap = d.dijkstra1(d.getNode("A"));
	for (map<Node, int>::iterator iter = shortestMap.begin(); iter != shortestMap.end(); ++iter) {
		cout << iter->first.name << " " << iter->second << endl;
	}
}

int main(void){
	test1();

	system("pause");
	return 0;
}

#include "DataLoader.h"

Graph DataLoader::loadData() {
	/*
	// 初始化学校地图
	Graph schoolMap;

	// 初始化点
	Node node1(3, "保卫处");
	Node node2(3, "京东快递站");
	Node node3(4, "西园十舍围合");
	Node node4(4, "西园二餐厅");
	Node node5(3, "西园六舍围合");
	Node node6(3, "西园一舍围合");
	Node node7(4, "华联超市");
	Node node8(4, "网球场");
	Node node9(6, "西园一餐厅");
	Node node10(3, "二号运动场");
	Node node11(3, "菜鸟驿站");
	Node node12(4, "工程训练中心");
	Node node13(4, "图书馆");
	Node node14(4, "第一教学楼");
	Node node15(3, "综合楼");
	Node node16(5, "第二基础实验楼");
	Node node17(4, "东园一餐厅");
	Node node18(4, "文科楼");
	Node node19(3, "一号运动场");
	Node node20(3, "东门");

	// 初始化边
	Edge egde1(698, node1, node2); // 保卫处到京东
	Edge egde2(698, node2, node1); // 京东到保卫处
	Edge egde3(680, node1, node3); // 保卫处到西园十舍
	Edge egde4(680, node3, node1); // 西园十舍到保卫处
	Edge egde5(50, node2, node4); // 京东到西园十舍
	Edge egde6(50, node4, node2); // 西园十舍到京东 
	Edge egde7(100, node2, node4); // 京东到西园二餐
	Edge egde8(100, node4, node2); // 西园二餐到京东
	Edge egde9(100, node3, node4); // 西园十舍到西园二餐
	Edge egde10(100, node4, node3); // 西园二餐到西园十舍
	Edge egde11(60, node4, node5); // 西园二餐到西园六舍
	Edge egde12(60, node5, node4); // 西园六舍到西园二餐
	Edge egde13(53, node5, node6); // 西园六舍到西园一舍
	Edge egde14(53, node6, node5); // 西园一舍到西园六舍

	return schoolMap;
	*/
	// 数据初始化
	Graph graph;
	// 初始化点集
	Node* A = new Node("A");
	Node* B = new Node("B");
	Node* C = new Node("C");
	Node* D = new Node("D");
	Node* E = new Node("E");
	
	// 初始化边集
	Edge AB(1, A, B);
	Edge BA(1, B, A);
	Edge AE(4, A, E);
	Edge EA(4, E, A);
	Edge AD(6, A, D);
	Edge DA(6, D, A);
	Edge BE(2, B, E);
	Edge EB(2, E, B);
	Edge DE(7, D, E);
	Edge ED(7, E, D);
	Edge BC(3, B, C);
	Edge CB(3, C, B);
	Edge CE(5, C, E);
	Edge EC(5, E, C);
	Edge CD(8, C, D);
	Edge DC(8, D, C);
	
	(*A).edges.push_back(AB);
	(*A).edges.push_back(AE);
	(*A).edges.push_back(AD);
	(*B).edges.push_back(BA);
	(*B).edges.push_back(BE);
	(*B).edges.push_back(BC);
	(*C).edges.push_back(CE);
	(*C).edges.push_back(CD);
	(*C).edges.push_back(CB);
	(*D).edges.push_back(DA);
	(*D).edges.push_back(DE);
	(*D).edges.push_back(DC);
	(*E).edges.push_back(EA);
	(*E).edges.push_back(EB);
	(*E).edges.push_back(EC);
	(*E).edges.push_back(ED);
	// 添加点集
	graph.nodes.insert(make_pair(1, *A));
	graph.nodes.insert(make_pair(2, *B));
	graph.nodes.insert(make_pair(3, *C));
	graph.nodes.insert(make_pair(4, *D));
	graph.nodes.insert(make_pair(5, *E));
	
	// 添加边集
	graph.edges.insert(AB);
	graph.edges.insert(BA);
	graph.edges.insert(AE);
	graph.edges.insert(EA);
	graph.edges.insert(AD);
	graph.edges.insert(DA);
	graph.edges.insert(BE);
	graph.edges.insert(EB);
	graph.edges.insert(ED);
	graph.edges.insert(DE);
	graph.edges.insert(BC);
	graph.edges.insert(CB);
	graph.edges.insert(EC);
	graph.edges.insert(CE);
	graph.edges.insert(DC);
	graph.edges.insert(CD);

	return graph;
}
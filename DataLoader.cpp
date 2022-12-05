#include "DataLoader.h"

Graph DataLoader::loadData() {
	// 初始化学校地图
	Graph schoolMap;

	// 初始化点
	Node* node1 = new Node("保卫处");
	Node* node2 = new Node("京东快递站");
	Node* node3 = new Node("西园十舍围合");
	Node* node4 = new Node("西园二餐厅");
	Node* node5 = new Node("西园六舍围合");
	Node* node6 = new Node("西园一舍围合");
	Node* node7 = new Node("华联超市");
	Node* node8 = new Node("网球场");
	Node* node9 = new Node("西园一餐厅");
	Node* node10 = new Node("二号运动场");
	Node* node11 = new Node("菜鸟驿站");
	Node* node12 = new Node("工程训练中心");
	Node* node13 = new Node("图书馆");
	Node* node14 = new Node("第一教学楼");
	Node* node15 = new Node("综合楼");
	Node* node16 = new Node("第二基础实验楼");
	Node* node17 = new Node("东园一餐厅");
	Node* node18 = new Node("文科楼");
	Node* node19 = new Node("一号运动场");
	Node* node20 = new Node("东门");

	// 初始化边
	Edge edge1(698, node1, node2); // 保卫处到京东
	Edge edge2(698, node2, node1); // 京东到保卫处
	Edge edge3(680, node1, node3); // 保卫处到西园十舍
	Edge edge4(680, node3, node1); // 西园十舍到保卫处
	Edge edge5(50, node2, node4); // 京东到西园十舍
	Edge edge6(50, node4, node2); // 西园十舍到京东 
	Edge edge7(100, node2, node4); // 京东到西园二餐
	Edge edge8(100, node4, node2); // 西园二餐到京东
	Edge edge9(100, node3, node4); // 西园十舍到西园二餐
	Edge edge10(100, node4, node3); // 西园二餐到西园十舍
	Edge edge11(60, node4, node5); // 西园二餐到西园六舍
	Edge edge12(60, node5, node4); // 西园六舍到西园二餐
	Edge edge13(53, node5, node6); // 西园六舍到西园一舍
	Edge edge14(53, node6, node5); // 西园一舍到西园六舍
	Edge edge15(330, node1, node8); // 保卫处到网球场
	Edge edge16(330, node8, node1); // 网球场到保卫处
	Edge edge17(530, node3, node8); // 西园十舍到网球场
	Edge edge18(530, node8, node3); // 网球场到西园十舍
	Edge edge19(155, node4, node7); // 西元二餐到华联
	Edge edge20(155, node7, node4); // 华联到西园二餐
	Edge edge21(230, node7, node5); // 华联到西园六舍
	Edge edge22(230, node5, node6); // 西园六舍到华联
	Edge edge23(170, node8, node9); // 网球场到西园一餐厅
	Edge edge24(170, node9, node8); // 西园一餐厅到网球场
	Edge edge25(130, node7, node9); // 华联到西园一餐
	Edge edge26(130, node9, node7); // 西园一餐到华联
	Edge edge27(510, node6, node10); // 西园一舍到二号场
	Edge edge28(510, node10, node6); // 二号场到西园一舍
	Edge edge29(640, node6, node11); // 西园一舍到菜鸟驿站
	Edge edge30(640, node11, node6); // 菜鸟驿站到西园一舍
	Edge edge31(260, node9, node10); // 西园一餐到二号场
	Edge edge32(260, node10, node9); // 二号场到西园一餐
	Edge edge33(160, node10, node11); // 二号场到菜鸟驿站 
	Edge edge34(160, node11, node10); // 菜鸟驿站到二号场
	Edge edge35(780, node9, node13); // 西园一餐到图书馆
	Edge edge36(780, node13, node9); // 图书馆到西园一餐
	Edge edge37(580, node9, node14); // 西园一餐到一教
	Edge edge38(580, node14, node9); // 一教到西园一餐
	Edge edge39(860, node11, node14); // 菜鸟驿站到一教
	Edge edge40(860, node14, node11); // 一教到菜鸟驿站
	Edge edge41(490, node13, node14); // 图书馆到一教 
	Edge edge42(490, node14, node13); // 一教到图书馆
	Edge edge43(1000, node9, node12); // 西园一餐到工训中心
	Edge edge44(1000, node12, node9); // 工训中序到西元一餐
	Edge edge45(610, node12, node13); // 工训中心到图书馆
	Edge edge46(610, node13, node12); // 图书馆到工训中心
	Edge edge47(350, node13, node16); // 图书馆到二基楼B
	Edge edge48(350, node16, node13); // 二基楼B到图书馆
	Edge edge49(810, node12, node16); // 工训中心到二基楼B
	Edge edge50(810, node16, node12); // 二基楼B到工训中心
	Edge edge51(720, node12, node17); // 工训中心到东园一餐
	Edge edge52(720, node17, node12); // 东园一餐到工训中心
	Edge edge53(360, node14, node15); // 一教到综合楼
	Edge edge54(360, node15, node14); // 综合楼到一教
	Edge edge55(660, node16, node15); // 二基楼B到综合楼
	Edge edge56(660, node15, node16); // 综合楼到二基楼B
	Edge edge57(460, node17, node16); // 东园一餐到二基楼B
	Edge edge58(460, node16, node17); // 二基楼B到东园一餐
	Edge edge59(190, node16, node18); // 二基楼B到文科楼
	Edge edge60(190, node18, node16); // 文科楼到二基楼B
	Edge edge61(500, node15, node19); // 综合楼到一号场
	Edge edge62(500, node19, node15); // 一号场到综合楼
	Edge edge63(400, node17, node18); // 东园一餐到文科楼
	Edge edge64(400, node18, node17); // 文科楼到东园一餐
	Edge edge65(500, node19, node18); // 一号场到文科楼
	Edge edge66(500, node18, node19); // 文科楼到一号场
	Edge edge67(410, node17, node20); // 东园一餐到东门
	Edge edge68(410, node20, node17); // 东门到东园一餐
	Edge edge69(360, node20, node18); // 东门到文科楼
	Edge edge70(360, node18, node20); // 文科楼到东门
	Edge edge71(720, node19, node20); // 一号场到东门
	Edge edge72(720, node20, node19); // 东门到一号场

	// 完善点对应的边集
	(*node1).edges.push_back(edge1);
	(*node1).edges.push_back(edge2);
	(*node1).edges.push_back(edge3);
	(*node1).edges.push_back(edge4);
	(*node1).edges.push_back(edge15);
	(*node1).edges.push_back(edge16);

	return schoolMap;
	
	
}

Graph DataLoader::loadTestData(){
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

#include "DataLoader.h"

Graph DataLoader::loadData() {
	/*
	// ��ʼ��ѧУ��ͼ
	Graph schoolMap;

	// ��ʼ����
	Node node1(3, "������");
	Node node2(3, "�������վ");
	Node node3(4, "��԰ʮ��Χ��");
	Node node4(4, "��԰������");
	Node node5(3, "��԰����Χ��");
	Node node6(3, "��԰һ��Χ��");
	Node node7(4, "��������");
	Node node8(4, "����");
	Node node9(6, "��԰һ����");
	Node node10(3, "�����˶���");
	Node node11(3, "������վ");
	Node node12(4, "����ѵ������");
	Node node13(4, "ͼ���");
	Node node14(4, "��һ��ѧ¥");
	Node node15(3, "�ۺ�¥");
	Node node16(5, "�ڶ�����ʵ��¥");
	Node node17(4, "��԰һ����");
	Node node18(4, "�Ŀ�¥");
	Node node19(3, "һ���˶���");
	Node node20(3, "����");

	// ��ʼ����
	Edge egde1(698, node1, node2); // ������������
	Edge egde2(698, node2, node1); // ������������
	Edge egde3(680, node1, node3); // ����������԰ʮ��
	Edge egde4(680, node3, node1); // ��԰ʮ�ᵽ������
	Edge egde5(50, node2, node4); // ��������԰ʮ��
	Edge egde6(50, node4, node2); // ��԰ʮ�ᵽ���� 
	Edge egde7(100, node2, node4); // ��������԰����
	Edge egde8(100, node4, node2); // ��԰���͵�����
	Edge egde9(100, node3, node4); // ��԰ʮ�ᵽ��԰����
	Edge egde10(100, node4, node3); // ��԰���͵���԰ʮ��
	Edge egde11(60, node4, node5); // ��԰���͵���԰����
	Edge egde12(60, node5, node4); // ��԰���ᵽ��԰����
	Edge egde13(53, node5, node6); // ��԰���ᵽ��԰һ��
	Edge egde14(53, node6, node5); // ��԰һ�ᵽ��԰����

	return schoolMap;
	*/
	// ���ݳ�ʼ��
	Graph graph;
	// ��ʼ���㼯
	Node* A = new Node("A");
	Node* B = new Node("B");
	Node* C = new Node("C");
	Node* D = new Node("D");
	Node* E = new Node("E");
	
	// ��ʼ���߼�
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
	// ��ӵ㼯
	graph.nodes.insert(make_pair(1, *A));
	graph.nodes.insert(make_pair(2, *B));
	graph.nodes.insert(make_pair(3, *C));
	graph.nodes.insert(make_pair(4, *D));
	graph.nodes.insert(make_pair(5, *E));
	
	// ��ӱ߼�
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
#include "DataLoader.h"

Graph DataLoader::loadData() {
	// ��ʼ��ѧУ��ͼ
	Graph schoolMap;

	// ��ʼ����
	Node* node1 = new Node("������");
	Node* node2 = new Node("�������վ");
	Node* node3 = new Node("��԰ʮ��Χ��");
	Node* node4 = new Node("��԰������");
	Node* node5 = new Node("��԰����Χ��");
	Node* node6 = new Node("��԰һ��Χ��");
	Node* node7 = new Node("��������");
	Node* node8 = new Node("����");
	Node* node9 = new Node("��԰һ����");
	Node* node10 = new Node("�����˶���");
	Node* node11 = new Node("������վ");
	Node* node12 = new Node("����ѵ������");
	Node* node13 = new Node("ͼ���");
	Node* node14 = new Node("��һ��ѧ¥");
	Node* node15 = new Node("�ۺ�¥");
	Node* node16 = new Node("�ڶ�����ʵ��¥");
	Node* node17 = new Node("��԰һ����");
	Node* node18 = new Node("�Ŀ�¥");
	Node* node19 = new Node("һ���˶���");
	Node* node20 = new Node("����");

	// ��ʼ����
	Edge edge1(698, node1, node2); // ������������
	Edge edge2(698, node2, node1); // ������������
	Edge edge3(680, node1, node3); // ����������԰ʮ��
	Edge edge4(680, node3, node1); // ��԰ʮ�ᵽ������
	Edge edge5(50, node2, node4); // ��������԰ʮ��
	Edge edge6(50, node4, node2); // ��԰ʮ�ᵽ���� 
	Edge edge7(100, node2, node4); // ��������԰����
	Edge edge8(100, node4, node2); // ��԰���͵�����
	Edge edge9(100, node3, node4); // ��԰ʮ�ᵽ��԰����
	Edge edge10(100, node4, node3); // ��԰���͵���԰ʮ��
	Edge edge11(60, node4, node5); // ��԰���͵���԰����
	Edge edge12(60, node5, node4); // ��԰���ᵽ��԰����
	Edge edge13(53, node5, node6); // ��԰���ᵽ��԰һ��
	Edge edge14(53, node6, node5); // ��԰һ�ᵽ��԰����
	Edge edge15(330, node1, node8); // ������������
	Edge edge16(330, node8, node1); // ���򳡵�������
	Edge edge17(530, node3, node8); // ��԰ʮ�ᵽ����
	Edge edge18(530, node8, node3); // ���򳡵���԰ʮ��
	Edge edge19(155, node4, node7); // ��Ԫ���͵�����
	Edge edge20(155, node7, node4); // ��������԰����
	Edge edge21(230, node7, node5); // ��������԰����
	Edge edge22(230, node5, node6); // ��԰���ᵽ����
	Edge edge23(170, node8, node9); // ���򳡵���԰һ����
	Edge edge24(170, node9, node8); // ��԰һ����������
	Edge edge25(130, node7, node9); // ��������԰һ��
	Edge edge26(130, node9, node7); // ��԰һ�͵�����
	Edge edge27(510, node6, node10); // ��԰һ�ᵽ���ų�
	Edge edge28(510, node10, node6); // ���ų�����԰һ��
	Edge edge29(640, node6, node11); // ��԰һ�ᵽ������վ
	Edge edge30(640, node11, node6); // ������վ����԰һ��
	Edge edge31(260, node9, node10); // ��԰һ�͵����ų�
	Edge edge32(260, node10, node9); // ���ų�����԰һ��
	Edge edge33(160, node10, node11); // ���ų���������վ 
	Edge edge34(160, node11, node10); // ������վ�����ų�
	Edge edge35(780, node9, node13); // ��԰һ�͵�ͼ���
	Edge edge36(780, node13, node9); // ͼ��ݵ���԰һ��
	Edge edge37(580, node9, node14); // ��԰һ�͵�һ��
	Edge edge38(580, node14, node9); // һ�̵���԰һ��
	Edge edge39(860, node11, node14); // ������վ��һ��
	Edge edge40(860, node14, node11); // һ�̵�������վ
	Edge edge41(490, node13, node14); // ͼ��ݵ�һ�� 
	Edge edge42(490, node14, node13); // һ�̵�ͼ���
	Edge edge43(1000, node9, node12); // ��԰һ�͵���ѵ����
	Edge edge44(1000, node12, node9); // ��ѵ������Ԫһ��
	Edge edge45(610, node12, node13); // ��ѵ���ĵ�ͼ���
	Edge edge46(610, node13, node12); // ͼ��ݵ���ѵ����
	Edge edge47(350, node13, node16); // ͼ��ݵ�����¥B
	Edge edge48(350, node16, node13); // ����¥B��ͼ���
	Edge edge49(810, node12, node16); // ��ѵ���ĵ�����¥B
	Edge edge50(810, node16, node12); // ����¥B����ѵ����
	Edge edge51(720, node12, node17); // ��ѵ���ĵ���԰һ��
	Edge edge52(720, node17, node12); // ��԰һ�͵���ѵ����
	Edge edge53(360, node14, node15); // һ�̵��ۺ�¥
	Edge edge54(360, node15, node14); // �ۺ�¥��һ��
	Edge edge55(660, node16, node15); // ����¥B���ۺ�¥
	Edge edge56(660, node15, node16); // �ۺ�¥������¥B
	Edge edge57(460, node17, node16); // ��԰һ�͵�����¥B
	Edge edge58(460, node16, node17); // ����¥B����԰һ��
	Edge edge59(190, node16, node18); // ����¥B���Ŀ�¥
	Edge edge60(190, node18, node16); // �Ŀ�¥������¥B
	Edge edge61(500, node15, node19); // �ۺ�¥��һ�ų�
	Edge edge62(500, node19, node15); // һ�ų����ۺ�¥
	Edge edge63(400, node17, node18); // ��԰һ�͵��Ŀ�¥
	Edge edge64(400, node18, node17); // �Ŀ�¥����԰һ��
	Edge edge65(500, node19, node18); // һ�ų����Ŀ�¥
	Edge edge66(500, node18, node19); // �Ŀ�¥��һ�ų�
	Edge edge67(410, node17, node20); // ��԰һ�͵�����
	Edge edge68(410, node20, node17); // ���ŵ���԰һ��
	Edge edge69(360, node20, node18); // ���ŵ��Ŀ�¥
	Edge edge70(360, node18, node20); // �Ŀ�¥������
	Edge edge71(720, node19, node20); // һ�ų�������
	Edge edge72(720, node20, node19); // ���ŵ�һ�ų�

	// ���Ƶ��Ӧ�ı߼�
	(*node1).edges.push_back(edge1);
	(*node1).edges.push_back(edge2);
	(*node1).edges.push_back(edge3);
	(*node1).edges.push_back(edge4);
	(*node1).edges.push_back(edge15);
	(*node1).edges.push_back(edge16);

	return schoolMap;
	
	
}

Graph DataLoader::loadTestData(){
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

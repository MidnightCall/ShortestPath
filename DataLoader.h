#pragma once
#include "Graph.h"

/**
 * @ClassName DataLoader
 * @brief ���ڼ���ѧУ��ͼ���࣬�����ɸ��������������ͼ��Ϣ 
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */

class DataLoader
{
public:
	/**
	 * @brief ��ʼ��ѧУ��ͼ
	 * @return ����һ��Graph��������а���ѧУ��ͼ��λ�ýڵ�͸��ڵ�֮��·����Ϣ
	 */
	Graph loadData();

	Graph loadTestData();
};


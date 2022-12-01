#pragma once
#include "Graph.h"

class DataLoader
{
public:
	/**
	 * @brief 初始化学校地图
	 * @return 返回一个Graph类对象，其中包含学校地图各位置节点和各节点之间路径信息
	 */
	Graph loadData();
};


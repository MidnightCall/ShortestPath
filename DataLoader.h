#pragma once
#include "Graph.h"

/**
 * @ClassName DataLoader
 * @brief 用于加载学校地图的类，后续可更改来添加其他地图信息 
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */

class DataLoader
{
public:
	/**
	 * @brief 初始化学校地图
	 * @return 返回一个Graph类对象，其中包含学校地图各位置节点和各节点之间路径信息
	 */
	Graph loadData();

	Graph loadTestData();
};


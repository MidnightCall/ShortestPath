#pragma once

class ShortestPathCalculatable
{
public:
	/**
	 * @brief 计算最短路径
	 * @param startingPoint 起点
	 * @param terminal 终点
	 */
	virtual void calculateShortestPath(Node startingPoint, Node terminal) = 0;
};


#pragma once

class ShortestPathCalculatable
{
public:
	/**
	 * @brief �������·��
	 * @param startingPoint ���
	 * @param terminal �յ�
	 */
	virtual void calculateShortestPath(Node startingPoint, Node terminal) = 0;
};


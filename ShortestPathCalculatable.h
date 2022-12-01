#pragma once

class ShortestPathCalculatable
{
public:
	/**
	 * @brief �������·��
	 * @param startingPoint ���
	 * @param terminal �յ�
	 */
	virtual int calculateShortestPath(Node startingPoint, Node terminal) = 0;
};


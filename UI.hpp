#ifndef UI_HPP_
#define UI_HPP_

// ---------- INCLUDES ---------------------------------------------------------------
#include<iostream>
using namespace std;

/**
 * @ClassName UI
 * @brief ���ڹ����û�������ز�������
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */
class UI {


    // ---------- PUBLIC FUNCTION --------------------------------------------------------
public:

    /**
     * @brief �û������ӡ
     */
    void printMenu() {
        
    }

    /**
     * @brief ��ȡ�û���ѡ���������û���ѡ���ڲ˵���ʱ������ʾ��������
     * @param lowerBound ѡ��Χ���½�
     * @param upperBound ѡ��Χ���Ͻ�
     * @return �����û�ѡ��Ľ����Ϊһ��������Χ�ڵ�����
     */
    int getchoice(int lowerBound, int upperBound) {
        int choice;
        cin >> choice;
        while (choice > upperBound || choice < lowerBound) {
            cout << "Invalid input, please input again:";
            cin >> choice;
        }
        return choice;
    }

    /**
     * @brief �������е����
     */
    void run() {
        
    }
};

#endif // !1
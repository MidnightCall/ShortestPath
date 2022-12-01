#ifndef UI_HPP_
#define UI_HPP_

// ---------- INCLUDES ---------------------------------------------------------------
#include<iostream>
using namespace std;

/**
 * @ClassName UI
 * @brief 用于管理用户界面相关操作的类
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/30 12:14
 * @brief Version: beta-1.0
 */
class UI {


    // ---------- PUBLIC FUNCTION --------------------------------------------------------
public:

    /**
     * @brief 用户界面打印
     */
    void printMenu() {
        
    }

    /**
     * @brief 获取用户的选择结果，当用户的选择不在菜单内时，会提示重新输入
     * @param lowerBound 选择范围的下界
     * @param upperBound 选择范围的上届
     * @return 返回用户选择的结果，为一个给定范围内的整数
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
     * @brief 程序运行的入口
     */
    void run() {
        
    }
};

#endif // !1
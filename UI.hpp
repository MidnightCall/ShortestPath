#ifndef UI_HPP_
#define UI_HPP_

// ---------- INCLUDES ---------------------------------------------------------------
#include<iostream>
#include "test.hpp"
using namespace std;

/**
 * @ClassName UI
 * @brief 用于管理用户界面相关操作的类
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/12/3 16:14
 * @brief Version: beta-1.0
 */
class UI {


    // ---------- PUBLIC FUNCTION --------------------------------------------------------
public:

    /**
     * @brief 菜单打印
     */
    void printMenu() {
        cout << "请选择你要进行的操作" << endl;
        cout << "1.展示地图" << endl;
        cout << "2.展示可供选择的节点列表" << endl;
        cout << "3.计算最短路径" << endl;
        cout << "4.退出" << endl;
    }

    /**
     * @brief 地图打印
     */
    void printMap() {
        cout << "地图如下：" << endl;
        cout << "                保卫处                     --------------工训中心---------------------------|-----------------" << endl;
        cout << "          |------|   |-----               |                                                  |                      |" << endl;
        cout << "         |                 |              |                                                  |                      |" << endl;
        cout << "         |               网球场           |                                                   |                   |" << endl;
        cout << "         |                 |              |                                                   |                    |           东园一餐--------------------" << endl;
        cout << "         |                 |              |                                                建环楼                  |             |                    |  " << endl;
        cout << "京东快递站                 |              |                                                   |                    |              |                   | " << endl;
        cout << "|                         |               |                                                   |                    |              |                   |" << endl;
        cout << "|-----        |---------                  |                                               图书馆-------二基楼----------------------文科楼-----------东门" << endl;
        cout << "        |        |                        |                                                 |                                         |                |" << endl;
        cout << "     西园二餐--------华联超市------西园一餐--------------------------------------------------                                          |               | " << endl;
        cout << "        |                                               |                    |                |                          |------------|                |" << endl;
        cout << "        |                                               |                    -----------        |                     |               |                |" << endl;
        cout << "     西园六舍                   二号运动场              |                                      |                     |                                 |" << endl;
        cout << "        |                           |                   |                                      |                    |                                  |" << endl;
        cout << "        |                           |                         -----------------------------  一教--------------综合楼 ----------|           |           |" << endl;
        cout << "     西园一舍--------------------菜鸟-------------------------|                                                   |--------------------一号运动场 ------|" << endl;
    }

    /**
     * @brief 打印可供选择的节点列表
     */
    void printList() {
        cout << "1.保卫处" << endl;
        cout << "2.京东快递站" << endl;
        cout << "3.西园十舍围合" << endl;
        cout << "4.西园二餐厅" << endl;
        cout << "5.西园六舍围合" << endl;
        cout << "6.西园一舍围合" << endl;
        cout << "7.华联超市" << endl;
        cout << "8.网球场" << endl;
        cout << "9.西园一餐厅" << endl;
        cout << "10.二号运动场" << endl;
        cout << "11.菜鸟驿站" << endl;
        cout << "12.工训中心" << endl;
        cout << "13.图书馆" << endl;
        cout << "14.第一教学楼" << endl;
        cout << "15.综合楼" << endl;
        cout << "16.第二基础实验楼" << endl;
        cout << "17.东园一餐厅" << endl;
        cout << "18.文科楼" << endl;
        cout << "19.一号运动场" << endl;
        cout << "20.东门" << endl;        
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
     * @brief 计算最短路径的操作
     */
    void calculate() {
        Dijkstra dijkstra;
        string start;
        string end;
        cout << "请输入起点:" << endl;
        cin >> start;
        Node startNode = dijkstra.getNode(start);
        while (startNode == NULLNODE) {
            cout << "不存在的节点，请重新输入正确的节点名:";
            cin >> start;
            startNode = dijkstra.getNode(start);
        }

        cout << "请输入终点:" << endl;
        cin >> end;
        Node endNode = dijkstra.getNode(end);
        while (endNode == NULLNODE) {
            cout << "不存在的节点，请重新输入正确的节点名:";
            cin >> end;
            endNode = dijkstra.getNode(end);
        }

        dijkstra.calculateShortestPath(dijkstra.getNode(start), dijkstra.getNode(end));
    }

    /**
     * @brief 程序运行的入口
     */
    void run() {
        int choice;
        cout << "欢迎使用导航系统" << endl;
        cout << "--------------------------------------" << endl;
        printMenu();
        choice = getchoice(1, 4);
        while (choice < 4 && choice >= 1){
            switch (choice) {
            case 1:
                printMap();
                break;
            case 2:
                printList();
                break;
            case 3:
                calculate();
                break;
            }
            system("pause");
            system("cls");
            printMenu();
            choice = getchoice(1, 4);
        } 
        system("cls");
        cout << "感谢使用" << endl;
    }
};

#endif // !1
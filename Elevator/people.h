#pragma once

#include <iostream>
#include <string>

// property: gotoFloor, initFloor, weight, status.
class People {
  public:
    
    People(int initFloor, bool valid=true); // init people, which gengerates people id, weight, gotoFloor. will be called by class floor.
    
    bool valid = true;

    int gotoFloor; // ���ĸ�¥��
    int initFloor; // ��ʼ¥��
    int id = 1;
    double weight;
    std::string status = "waiting";
    // �����������
    double generateWeight();

    int generateFloor();

    void peopleLog();

    void peopleLeaveLog(int floorNum);

    static int peopleID;
};

#pragma once
#include "draw.h"
#include "global.h"
#include <chrono>
#include <thread>
#include <vector>
#include "draw.h"
#include "global.h"
#include "people.h"

class Elevator {
    public:
    char elevatorDirection = 'd'; // direcion of elevator
    int elevatorPositionX = 1;
    int elevatorPositionY = 1;
    int currentFloor = 5;

    std::vector<People> peopleList; // people on that elevator
    // init function for elevator. It needs to draw elevator.
    Elevator() ;
    
    void drawElevator();
    void drawElevatorWithCoordinates(int x, int y);
    void deleteElevator();
    void deleteElevatorWithCoordinates(int x, int y);
    // 电梯下移5格（调用5次goDownElevator）
    void goDownFloor();

    // 电梯上移5格（调用5次goUpElevator）
    void goUpFloor();

    // 电梯关门
    void closeDoor();

    // 绘制电梯方向
    void drawElevatorDirection();

    // 根据方向自动运行, the direction won't change, but will move to the first place have people
    void go(char direction);

    void changeDirection();

    void pushPeople(People people);

    bool isVoid();

 std::vector<People> clean(int floorNum);   
private:
    // go only one floor; must be private.
    void goDownElevator();
    void goUpElevator();
};



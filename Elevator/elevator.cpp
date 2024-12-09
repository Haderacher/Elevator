#include "elevator.h"
#include "people.h"
#include <algorithm>
#include "console.h"



Elevator::Elevator() {
    this->elevatorDirection = 'd';
    this->elevatorPositionX = 1;
    this->elevatorPositionY = 1;
    drawElevator(); 
}




// 画一个电梯。输入坐标
void Elevator::drawElevatorWithCoordinates(int x, int y) {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        drawBlock(x + i, y);
        drawBlock(x + i, y + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        drawBlock(x, y + i);
        drawBlock(x + ELEVATOR_WIDTH - 1, y + i);
    }
}

// 删除指定坐标的电梯
void Elevator::deleteElevatorWithCoordinates(int x, int y) {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        deleteGrid(x + i, y);
        deleteGrid(x + i, y + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        deleteGrid(x, y + i);
        deleteGrid(x + ELEVATOR_WIDTH - 1, y + i);
    }
    //  drawElevatorDirection();
}

// 画一个电梯，位置由程序操控
void Elevator::drawElevator() {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        drawBlock(elevatorPositionX + i, elevatorPositionY);
        drawBlock(elevatorPositionX + i,
                  elevatorPositionY + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        drawBlock(elevatorPositionX, elevatorPositionY + i);
        drawBlock(elevatorPositionX + ELEVATOR_WIDTH - 1,
                  elevatorPositionY + i);
    }

    //  drawElevatorDirection();

}

// 删除（隐藏）电梯
void Elevator::deleteElevator() {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        deleteGrid(elevatorPositionX + i, elevatorPositionY);
        deleteGrid(elevatorPositionX + i,
                   elevatorPositionY + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        deleteGrid(elevatorPositionX, elevatorPositionY + i);
        deleteGrid(elevatorPositionX + ELEVATOR_WIDTH - 1,
                   elevatorPositionY + i);
    }
}

// 电梯下移一格，（会先删除原有的电梯，然后重新绘制电梯）
void Elevator::goDownElevator() {
    // 更新方向
    elevatorDirection = 'd';
    // 删除电梯
    deleteElevator();
    // 电梯坐标下移
    elevatorPositionY += 1;
    // 重新绘制电梯
    drawElevator();
}

// 电梯上移一格，（会先删除原有的电梯，然后重新绘制电梯）
void Elevator::goUpElevator() {
    elevatorDirection = 'u';
    deleteElevator();
    elevatorPositionY -= 1;
    drawElevator();
}

// 下移5格
void Elevator::goDownFloor() {
    std::vector<std::string> log;
    log.push_back("电梯下行");
    printLogWithMargin(61, 1, log);
    this->currentFloor -= 1;
    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        goDownElevator();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

// 上移5格
void Elevator::goUpFloor() {
    std::vector<std::string> log;
    log.push_back("电梯上行");
    printLogWithMargin(61, 1, log);
    this->currentFloor += 1;
    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        goUpElevator();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}


void Elevator::closeDoor() {
    int doorX = ELEVATOR_WIDTH;
    int doorY = elevatorPositionY;

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        deleteGrid(doorX, doorY + i);
    }
}

void Elevator::drawElevatorDirection() {
    int x = elevatorPositionX + ELEVATOR_WIDTH - 2;
    int y = elevatorPositionY + ELEVATOR_HEIGHT / 2;

    if (elevatorDirection == 'u') {
        DrawUpTriangle(x, y);
    } else {
        DrawDownTriangle(x, y);
    }
}

void Elevator::go(char direction) {
    if (direction == 'd') {
        goDownFloor();
    } else if (direction == 'u') {
        goUpFloor();
    }
}


// change direction.
void Elevator::changeDirection() {
    if (elevatorDirection == 'u') {
        elevatorDirection = 'd';
    } else {
        elevatorDirection = 'u';
    }
}

void Elevator::pushPeople(People people) {
    this->peopleList.push_back(people);

}


bool Elevator::isVoid() {
    if (peopleList.empty()) {
        return true;
    } 
    return false;
}


std::vector<People> Elevator::clean(int floorNum) {
    std::vector<People> gone = {};

    for (auto people : peopleList) {
        if (people.gotoFloor == floorNum)
        people.peopleLeaveLog(floorNum);
    }
    
    auto it = std::remove_if(peopleList.begin(), peopleList.end(), [&gone, floorNum] (const People& people) {
            if (people.gotoFloor == floorNum) {
            gone.push_back(people);
            return true;
            }
            return false;
            }
            );

    peopleList.erase(it, peopleList.end());
        return gone;
};

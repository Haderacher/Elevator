#pragma once

#include "floor.h"
#include "people.h"
#include "vector"

class FloorManager {
public:
    std::vector<Floor> FloorList;

    // this is the function that creates the floors.
    FloorManager();

    void generateRandomPeople();

    bool checkUp(int x);

    bool checkDown(int x);

    People popPeople(int floorNum);

    bool isVoid();
};

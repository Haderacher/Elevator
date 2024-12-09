#pragma once
#include "people.h"
#include "utility.h"
#include <vector>


// property: peopleMax, peopleList
class Floor {
  public:
    int peopleMax = 5;
    int peopleNum = 0;
    std::vector<People> peopleList;
    Floor(int floorNum);
    
    People pop();

    // frontend functions.
    void drawFloor();

    bool check();
};


#pragma once

#include "draw.h"
#include "global.h"
#include <vector>
#include <Windows.h>

const int xPassengerConsoleStart =
    BORDERWIDTH + ELEVATOR_WIDTH + FLOOR_WIDTH + 1;
const int yPassengerConsoleStart = BORDERWIDTH;

void printPassengerLog(const char *s);


void testLog(const char* s);


void printLogWithMargin(int x, int y, const std::vector<std::string> &logs);


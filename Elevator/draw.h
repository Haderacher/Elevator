#pragma once

#include "people.h"
#include <windows.h>
#include <winnt.h>

void setCursorPosition(int x, int y);

void setTextColor();

void resetTextColor();

void drawVerticalLine(int x, int y);

void drawBlock(int x, int y);

void deleteGrid(int x, int y);

void drawWallBlock(int x, int y);

void drawHorizontalLine(int x, int y);

void drawNumber(int num, int x, int y);

void DrawChar(char c, int x, int y);

void DrawString(const char *c, int x, int y);

void DrawUpTriangle(int x, int y);

void DrawDownTriangle(int x, int y);

void drawPeopleInitPosition(People people);

void DrawDebug(int x, int y);
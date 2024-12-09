#include "window.h"
#include "draw.h"
#include "global.h"

void windowInit() {
    // for (int i = 0; i < WIDTH; i++)
    //{
    //	drawHorizontalLine(i, 0);
    //	drawHorizontalLine(i, 37);
    // }

    // ����ˮƽ�߿�
    for (int i = 0; i < WIDTH; i++) {
        drawHorizontalLine(i, 0); // for debug purpose
        drawHorizontalLine(i, 37);
    }

    // ���ƴ�ֱ�߿�
    for (int j = 0; j < HEIGHT + 2 * BORDERWIDTH; j++) {
        drawVerticalLine(0, j); // for debug purpose
        drawVerticalLine(WIDTH, j);
    }

    // ����¥��
    int xInitPosition = BORDERWIDTH + ELEVATOR_WIDTH; // ¥�������ʼ��
    int yInitPosition = BORDERWIDTH;
    for (int j = 7; j < 40; j += 7) {
        for (int i = 0; i < FLOOR_WIDTH; i++) {
            drawWallBlock(xInitPosition + i, j);
        }
    }

    // ���ƴ�ֱ�ߣ�ˮƽ��������
    int vPosition = BORDERWIDTH + ELEVATOR_WIDTH + FLOOR_WIDTH; //  ��־���Ҳ�
    for (int i = 0; i < HEIGHT; i++) {
        drawWallBlock(vPosition, i);

    }

    // ����¥������
    int floorLeft = xInitPosition;
    for (int i = 0; i < 5; i++) {
        drawNumber(5 - i, floorLeft + FLOOR_WIDTH - 2,
                   BORDERWIDTH + i * FLOOR_HEIGHT);
    }
}
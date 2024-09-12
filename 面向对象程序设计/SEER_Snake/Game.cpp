#include <conio.h>
#include "SEER_Snake.h"

using namespace std;

void getDirection(Direction& direction_1, Direction& direction_2)
{
    if (_kbhit()) {
        int key = _getch();
        if (key == 0 || key == 0xE0) {
            key = _getch();
            if (key == 'H' && direction_2 != Down)
                direction_2 = Up;
            else if (key == 'P' && direction_2 != Up)
                direction_2 = Down;
            else if (key == 'K' && direction_2 != Right)
                direction_2 = Left;
            else if (key == 'M' && direction_2 != Left)
                direction_2 = Right;
        }
        else if (key == 'p' || key == 'P')
            system("pause");
        else {
            if ((key == 'W' || key == 'w') && direction_1 != Down)
                direction_1 = Up;
            else if ((key == 'S' || key == 's') && direction_1 != Up)
                direction_1 = Down;
            else if ((key == 'A' || key == 'a') && direction_1 != Right)
                direction_1 = Left;
            else if ((key == 'D' || key == 'd') && direction_1 != Left)
                direction_1 = Right;
        }
    }
}

void SEER_Snake(Mode mode)
{
    initialize_graphics(mode);
    Control control(mode);
    bool flag = true;
    int lastLength = 1;

    if (mode == BasicMode || mode == AdvancedMode || mode == ExpertMode) {
        while (flag) {
            bool is_generate = control.Snake_1.generateSnake();
            if (!is_generate) {
                if (mode == AdvancedMode)
                    control.Snake_1.correct(lastLength);
                break;
            }
            Sleep(timeThreshold);

            while (true) {
                if (control.Snake_1.getLength() == (gridRow - 2) * (gridCol - 2)) {
                    flag = false;
                    break;
                }

                for (int i = energy; i <= meteoric; i++)
                    control.generateGrid((GridCondition)i);

                control.print_information();

                Direction direction = control.Snake_1.getSnakeDirection();
                getDirection(direction, direction);

                if (!control.Snake_1.changeDirection(direction)) {
                    control.print_information();
                    break;
                }
                Sleep(timeThreshold);
            }

            switch (mode) {
                case BasicMode:
                    flag = false;
                    break;
                case AdvancedMode:
                    control.Snake_1.changeGridCondition(GridWall);
                    control.refreshMap();
                    lastLength = control.Snake_1.getLength();
                    control.Snake_1.refreshSnake();
                    flag = true;
                    break;
                case ExpertMode:
                    control.Snake_1.changeGridCondition(energy);
                    control.refreshMap();
                    lastLength = control.Snake_1.getLength();
                    control.Snake_1.refreshSnake();
                    if (control.Snake_1.getDeath() >= deathCountMax) {
                        control.Snake_1.correct(lastLength);
                        flag = false;
                    }
                    else
                        flag = true;
                    break;
                default:
                    exit(-1);
            }
        }
    }
    else if (mode == HumanVsHumanMode || mode == HumanVsAIMode) {
        while (flag) {
            bool is_generate_1 = control.Snake_1.generateSnake(true);
            bool is_generate_2 = control.Snake_2.generateSnake(true);
            if (!is_generate_1 || !is_generate_2)
                break;
            Sleep(timeThreshold);

            while (true) {
                if (control.Snake_1.getLength() + control.Snake_2.getLength() == (gridRow - 2) * (gridCol - 2)) {
                    flag = false;
                    break;
                }

                for (int i = energy; i <= meteoric; i++)
                    control.generateGrid((GridCondition)i);

                control.print_information();

                Direction direction_1 = control.Snake_1.getSnakeDirection();
                Direction direction_2 = control.Snake_2.getSnakeDirection();
                switch (mode) {
                    case HumanVsHumanMode:
                        getDirection(direction_1, direction_2);
                        break;
                    case HumanVsAIMode:
                        getDirection(direction_1, direction_1);
                        direction_2 = control.Snake_2.BFS();
                        break;
                    default:
                        exit(-1);
                }

                if (!control.Snake_1.changeDirection(direction_1)) {
                    control.print_information();
                    flag = false;
                    break;
                }
                if (!control.Snake_2.changeDirection(direction_2)) {
                    control.print_information();
                    flag = false;
                    break;
                }
                Sleep(timeThreshold);
            }
        }
    }
    else
        exit(-1);

    control.print_information();

    if (control.getHighestScore() > readHighestScore(mode))
        updateHighestScore(mode, control.getHighestScore());

    endPage();
}
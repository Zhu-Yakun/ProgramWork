#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SEER_Snake.h"

using namespace std;

void Control::Initialize(int*& p)
{
    p = new(nothrow) int;
    if (p == nullptr)
        exit(-1);
    *p = 0;
}

int Control::count(GridCondition gridCondition)
{
    int blanks = 0;
    for (int i = 1; i < gridRow - 1; i++)
        for (int j = 1; j < gridCol - 1; j++)
            if (map[i][j] == gridCondition)
                blanks++;
    return blanks;
}

Control::Control(Mode _mode) : mode(_mode), startTickCount(GetTickCount()), PauseLenth(0) {
    map = new(nothrow) GridCondition * [gridRow];
    if (!map)
        exit(-1);

    for (int i = 0; i < gridRow; ++i) {
        map[i] = new(nothrow) GridCondition[gridCol];
        if (!map[i])
            exit(-1);
        for (int j = 0; j < gridCol; ++j) {
            map[i][j] = (i == 0 || i == gridRow - 1 || j == 0 || j == gridCol - 1) ? GridWall : GridBlank;
            print_status(i, j, map[i][j]);
        }
    }

    Initialize(penergy);
    Initialize(pS_energy);
    Initialize(ppitate);
    Initialize(pDene);
    Initialize(pmeteoric);

    Snake_1.snakeCategory = Snake1;
    Snake_1.map = map;
    Snake_1.penergy = penergy;
    Snake_1.pS_energy = pS_energy;
    Snake_1.ppitate = ppitate;
    Snake_1.pDene = pDene;
    Snake_1.pmeteoric = pmeteoric;

    Snake_2.snakeCategory = Snake2;
    Snake_2.map = map;
    Snake_2.penergy = penergy;
    Snake_2.pS_energy = pS_energy;
    Snake_2.ppitate = ppitate;
    Snake_2.pDene = pDene;
    Snake_2.pmeteoric = pmeteoric;
}

Control::~Control()
{
    for (int i = 0; i < gridRow; i++)
        delete[] map[i];
    delete[] map;
    delete penergy;
    delete pS_energy;
    delete ppitate;
    delete pDene;
    delete pmeteoric;
}

void Control::generateGrid(GridCondition gridCondition)
{
    int blanks = count(GridBlank), n;
    if (blanks == 0)
        return;
    switch (gridCondition) {
        case energy:
            n = maxenergy - *penergy;
            break;
        case pitate:
            n = maxpitate - *ppitate;
            break;
        case meteoric:
            n = maxmeteoric - *pmeteoric;
            break;
        case S_energy:
            n = maxS_energy - *pS_energy;
            break;
        case Dene:
            n = maxDene - *pDene;
            break;
        default:
            exit(-1);
    }
    if (n <= 0)
        return;
    else if (n > blanks)
        n = blanks;

    for (int i = 0; i < n; i++)
        while (true) {
            int row = rand() % (gridRow - 2) + 1, col = rand() % (gridCol - 2) + 1;
            if (map[row][col] == GridBlank) {
                map[row][col] = gridCondition;
                print_status(row, col, gridCondition);
                switch (gridCondition) {
                    case energy:
                        (*penergy)++;
                        break;
                    case pitate:
                        (*ppitate)++;
                        break;
                    case meteoric:
                        (*pmeteoric)++;
                        break;
                    case S_energy:
                        (*pS_energy)++;
                        break;
                    case Dene:
                        (*pDene)++;
                        break;
                    default:
                        exit(-1);
                }
                break;
            }
        }
}

void Control::print_information()
{
    TCHAR infoText[256];
    DWORD endTickCount = GetTickCount();
    int elapsedSeconds = (endTickCount - startTickCount) / 1000;
    switch (mode) {
        case BasicMode:
            _stprintf(infoText, _T("[基础模式]  能源数量：%-*d队伍长度：%-*d游戏时间：%02d:%02d"), dataLength, Snake_1.score, dataLength, Snake_1.length, elapsedSeconds / 60, elapsedSeconds % 60);
            break;
        case AdvancedMode:
            _stprintf(infoText, _T("[进阶模式]  能源数量：%-*d队伍长度：%-*d死亡次数：%-*d游戏时间：%02d:%02d"), dataLength, Snake_1.score, dataLength, Snake_1.length, dataLength, Snake_1.death, elapsedSeconds / 60, elapsedSeconds % 60);
            break;
        case ExpertMode:
            _stprintf(infoText, _T("[高级模式]  能源数量：%-*d队伍长度：%-*d死亡次数：%-*d游戏时间：%02d:%02d"), dataLength, Snake_1.score, dataLength, Snake_1.length, dataLength, Snake_1.death, elapsedSeconds / 60, elapsedSeconds % 60);
            break;
        case HumanVsHumanMode:
            _stprintf(infoText, _T("[双人对战]  赛小息得分：%-*d赛小息长度：%-*d卡璐璐得分：%-*d卡璐璐长度：%-*d游戏时间：%02d:%02d"), dataLength, Snake_1.score, dataLength, Snake_1.length, dataLength, Snake_2.score, dataLength, Snake_2.length, elapsedSeconds / 60, elapsedSeconds % 60);
            break;
        case HumanVsAIMode:
            _stprintf(infoText, _T("[人机对战]  赛小息得分：%-*d赛小息长度：%-*d卡璐璐(AI)得分：%-*d卡璐璐(AI)长度：%-*d游戏时间：%02d:%02d"), dataLength, Snake_1.score, dataLength, Snake_1.length, dataLength, Snake_2.score, dataLength, Snake_2.length, elapsedSeconds / 60, elapsedSeconds % 60);
            break;
        default:
            exit(-1);
    }

    settextstyle(&Font);
    settextcolor(WHITE);
    outtextxy(leftGridMargin, topInfoMargin, infoText);
}

void Control::refreshMap()
{
    *penergy = count(GridCondition::energy);
    *pS_energy = count(GridCondition::S_energy);
    *ppitate = count(GridCondition::pitate);
    *pDene = count(GridCondition::Dene);
    *pmeteoric = count(GridCondition::meteoric);
}
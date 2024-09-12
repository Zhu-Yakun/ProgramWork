#pragma once
#include <graphics.h>
#include <Windows.h>
#include<algorithm>

using namespace std;

#define MODE_NUMBER 5
// 非法参数
#define INVALID_ROW -1
#define INVALID_COLUMN -1

// 窗口、网格参数
const int menuWidth = 1024;
const int menuHeight = 512;
const int gridRow = 24;
const int gridCol = 48;
const int gridSideLength = 24;
const int gridSpace = 1;
// 间隙距离
const int topInfoMargin = 10;
const int bottomInfoMargin = 10;
const int topGridMargin = 40;
const int bottomGridMargin = 10;
const int leftGridMargin = 10;
const int rightGridMargin = 10;

const int dataLength = 6;
const int startTime = 1500;
const int snakeInitialLength = 5;

// 得分物参数
const int maxenergy = 12;
const int maxS_energy = 4;
const int maxpitate = 6;
const int maxDene = 2;
const int maxmeteoric = 4;

const int energyScore = 10;
const int S_energyScore = 50;
const int pitateScore = -20;
const int DeneScore = -40;
const int meteoricScore = -30;

const int deathScore = -100;
const int deathCountMax = 10;

const int timeThreshold = 200;

enum Mode { BasicMode, AdvancedMode, ExpertMode, HumanVsHumanMode, HumanVsAIMode, ResetHighestScore, Quit };
enum SnakeCategory { Snake1, Snake2, InvalidSnakeCategory };
enum GridCondition { GridBlank, GridWall, SnakeHead, SnakeBody, energy, S_energy, pitate, Dene, meteoric };
enum Direction { Up, Down, Left, Right, InvalidDirection };

const LOGFONT Font{ (topGridMargin - topInfoMargin - bottomInfoMargin), (topGridMargin - topInfoMargin - bottomInfoMargin) / 2, 0, 0, FW_DONTCARE, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH, L"楷体" };


void startPage();
Mode menu();
void endPage();

void updateHighestScore(Mode mode, int score);
int readHighestScore(Mode mode);
void reset();

void SEER_Snake(Mode mode);

void drawGridLines();
void displayHighestScore(Mode mode);
void initialize_graphics(Mode mode);
void print_status(int row, int col, GridCondition gridCondition, SnakeCategory snakeCategory = InvalidSnakeCategory, Direction direction = InvalidDirection);


struct Point{
    int row;
    int col;
};

class Snake {
private:
    struct SnakeSegment {
        COORD coordinate;
        Direction direction;
        SnakeSegment* nextSegment;
    };
    SnakeCategory snakeCategory;
    GridCondition** map;
    SnakeSegment* head;
    SnakeSegment* tail;

    int* penergy;
    int* pS_energy;
    int* ppitate;
    int* pDene;
    int* pmeteoric;

    int score = 0;
    int length = 1;
    int death = 0;

    void addSegment(Direction direction);
    void deleteSegment();
    void deleteSnake();

    bool findEmptySpace(COORD& coord, Direction& direction, bool is_double);
    Point findClosestCoordinate();
    Point findNextStep(int map[][gridCol], int startRow, int startCol, int targetRow, int targetCol);
public:
    friend class Control;
    bool generateSnake(bool is_double = false);
    void refreshSnake();

    void changeGridCondition(GridCondition gridCondition);
    bool changeDirection(Direction direction);

    Direction BFS();

    ~Snake() {
        if (head != nullptr)
            deleteSnake();
    }
    int getLength() {
        return length;
    }
    int getDeath() {
        return death;
    }
    void correct(int len) {
        length = len;
    }
    Direction getSnakeDirection() {
        return head->direction;
    }
};

class Control {
private:
    Mode mode;
    DWORD startTickCount;
    GridCondition** map;

    int* penergy;
    int* pS_energy;
    int* ppitate;
    int* pDene;
    int* pmeteoric;

    void Initialize(int*& p);
    int count(GridCondition gridCondition);
public:
    Snake Snake_1;
    Snake Snake_2;

    DWORD PauseLenth;

    Control(Mode _mode);
    ~Control();

    void generateGrid(GridCondition gridCondition);
    void print_information();
    void refreshMap();
    int getHighestScore() {
        return max(Snake_1.score, Snake_2.score);
    }
};
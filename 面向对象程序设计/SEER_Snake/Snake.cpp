#include<iostream>
#include<queue>
#include "SEER_Snake.h"

using namespace std;

void Snake::addSegment(Direction direction) {
    int newX = tail->coordinate.X;
    int newY = tail->coordinate.Y;
    switch (direction) {
        case Up:
            newY++;
            break;
        case Down:
            newY--;
            break;
        case Left:
            newX++;
            break;
        case Right:
            newX--;
            break;
        default:
            exit(-1);
    }

    SnakeSegment* newSegment = new SnakeSegment;
    newSegment->coordinate.X = newX;
    newSegment->coordinate.Y = newY;
    newSegment->direction = direction;
    newSegment->nextSegment = nullptr;

    tail->nextSegment = newSegment;
    tail = newSegment;

    map[newY][newX] = SnakeBody;
    print_status(newY, newX, SnakeBody, snakeCategory, this->getSnakeDirection());

    length++;
}

void Snake::deleteSegment() {
    if (length <= 1)
        return;

    SnakeSegment* prev = nullptr;
    SnakeSegment* segment = head;
    while (segment->nextSegment) {
        prev = segment;
        segment = segment->nextSegment;
    }

    map[segment->coordinate.Y][segment->coordinate.X] = GridBlank;
    print_status(segment->coordinate.Y, segment->coordinate.X, GridBlank, snakeCategory, this->getSnakeDirection());

    delete segment;
    if (prev) {
        prev->nextSegment = nullptr;
        tail = prev;
    }
    else
        head = tail = nullptr;

    length--;
}

void Snake::deleteSnake() {
    while (head) {
        SnakeSegment* temp = head;
        head = head->nextSegment;
        delete temp;
    }
    tail = nullptr;
    length = 0;
}

Point Snake::findClosestCoordinate() {
    int maxDistance = max(gridRow, gridCol) - 3;
    Point closest = { INVALID_ROW, INVALID_COLUMN };

    for (int distance = 1; distance <= maxDistance; distance++) {
        Point start = { max(head->coordinate.Y - distance, 1), max(head->coordinate.X - distance, 1) };
        Point end = { min(head->coordinate.Y + distance, gridRow - 2), min(head->coordinate.X + distance, gridCol - 2) };

        for (int r = start.row; r <= end.row; r++) {
            for (int c = start.col; c <= end.col; c++) {
                if ((r == head->coordinate.Y - distance || r == head->coordinate.Y + distance ||
                    c == head->coordinate.X - distance || c == head->coordinate.X + distance) &&
                    (map[r][c] == energy || map[r][c] == S_energy)) {
                    closest = { r, c };
                    return closest;
                }
            }
        }
    }
    return closest;
}

Point Snake::findNextStep(int map[][gridCol], int startRow, int startCol, int targetRow, int targetCol) {
    static const int dx[] = { -1, 1, 0, 0 };
    static const int dy[] = { 0, 0, -1, 1 };

    bool visited[gridRow][gridCol] = { false };
    Point parent[gridRow][gridCol] = { { INVALID_ROW, INVALID_COLUMN } };
    queue<Point> queue;

    visited[startRow][startCol] = true;
    parent[startRow][startCol] = { INVALID_ROW, INVALID_COLUMN };
    queue.push({ startRow, startCol });

    while (!queue.empty()) {
        Point current = queue.front();
        queue.pop();

        if (current.row == targetRow && current.col == targetCol) {
            while (parent[current.row][current.col].row != startRow || parent[current.row][current.col].col != startCol) {
                current = parent[current.row][current.col];
            }
            return current;
        }

        for (int dir = 0; dir < 4; dir++) {
            int newRow = current.row + dy[dir];
            int newCol = current.col + dx[dir];

            if (newRow >= 1 && newRow < gridRow - 1 && newCol >= 1 && newCol < gridCol - 1 && map[newRow][newCol] == GridBlank && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = current;
                queue.push({ newRow, newCol });
            }
        }
    }
    return { INVALID_ROW, INVALID_COLUMN };
}

bool Snake::generateSnake(bool is_double) {
    COORD start;
    Direction direction;

    if (!findEmptySpace(start, direction, is_double))
        return false;

    SnakeSegment* newHead = new SnakeSegment{ start, direction, nullptr };
    map[start.Y][start.X] = SnakeHead;
    print_status(start.Y, start.X, SnakeHead, snakeCategory, direction);

    head = tail = newHead;

    for (int i = 1; i < snakeInitialLength; i++)
        addSegment(direction);
    return true;
}

bool Snake::findEmptySpace(COORD& coord, Direction& direction, bool is_double)
{
    if (!is_double || (is_double && snakeCategory == Snake2))
        for (int i = 1; i < gridRow - 1; i++)
            for (int j = 1; j < gridCol - snakeInitialLength; j++) {
                bool isEmptySpace = true;
                for (int k = 0; k < snakeInitialLength; k++)
                    if (map[i][j + k] != GridBlank) {
                        isEmptySpace = false;
                        break;
                    }
                if (isEmptySpace) {
                    coord.Y = i;
                    coord.X = j + snakeInitialLength - 1;
                    direction = Right;
                    return true;
                }
            }

    if (!is_double || (is_double && snakeCategory == Snake1))
        for (int i = 1; i < gridRow - snakeInitialLength; i++)
            for (int j = 1; j < gridCol - 1; j++) {
                bool isEmptySpace = true;
                for (int k = 0; k < snakeInitialLength; k++)
                    if (map[i + k][j] != GridBlank) {
                        isEmptySpace = false;
                        break;
                    }
                if (isEmptySpace) {
                    coord.Y = i + snakeInitialLength - 1;
                    coord.X = j;
                    direction = Down;
                    return true;
                }
            }
    return false;
}


void Snake::refreshSnake()
{
    deleteSnake();
    length = 1;
    death++;
    score += deathScore;
}


void Snake::changeGridCondition(GridCondition gridCondition)
{
    SnakeSegment* currentSegment = head;
    while (currentSegment != nullptr) {
        COORD coordinate = currentSegment->coordinate;
        map[coordinate.Y][coordinate.X] = gridCondition;
        print_status(coordinate.Y, coordinate.X, gridCondition);
        currentSegment = currentSegment->nextSegment;
    }
}

bool Snake::changeDirection(Direction direction)
{
    Direction tailDirection = tail->direction;
    map[head->coordinate.Y][head->coordinate.X] = SnakeBody;
    print_status(head->coordinate.Y, head->coordinate.X, SnakeBody, snakeCategory, this->getSnakeDirection());
    map[tail->coordinate.Y][tail->coordinate.X] = GridBlank;
    print_status(tail->coordinate.Y, tail->coordinate.X, GridBlank, snakeCategory, this->getSnakeDirection());

    COORD prevHeadCoord = head->coordinate;
    head->direction = direction;
    switch (direction) {
        case Up:
            head->coordinate.Y--;
            break;
        case Down:
            head->coordinate.Y++;
            break;
        case Left:
            head->coordinate.X--;
            break;
        case Right:
            head->coordinate.X++;
            break;
    }

    SnakeSegment* currentSegment = head->nextSegment, * previousSegment = head;
    while (currentSegment != nullptr) {
        COORD prevCoord = currentSegment->coordinate;
        Direction prevDirection = currentSegment->direction;
        currentSegment->coordinate = prevHeadCoord;
        currentSegment->direction = prevDirection;
        prevHeadCoord = prevCoord;
        currentSegment = currentSegment->nextSegment;
    }
    GridCondition nextCondition = map[head->coordinate.Y][head->coordinate.X];
    currentSegment = head->nextSegment;
    Direction tempDirection = previousSegment->direction;
    while (currentSegment != nullptr) {
        Direction currentDirection = currentSegment->direction;
        currentSegment->direction = tempDirection;
        tempDirection = currentDirection;
        previousSegment = currentSegment;
        currentSegment = currentSegment->nextSegment;
    }

    map[head->coordinate.Y][head->coordinate.X] = SnakeHead;
    print_status(head->coordinate.Y, head->coordinate.X, SnakeHead, snakeCategory, this->getSnakeDirection());

    switch (nextCondition) {
        case GridBlank:
            break;
        case GridWall:
        case SnakeHead:
        case SnakeBody:
            return false;
        case energy:
            addSegment(tailDirection);
            score += energyScore;
            (*penergy)--;
            break;
        case pitate:
            score += pitateScore;
            (*ppitate)--;
            break;
        case meteoric:
            deleteSegment();
            deleteSegment();
            score += meteoricScore;
            (*pmeteoric)--;
            break;
        case S_energy:
            score += S_energyScore;
            (*pS_energy)--;
            break;
        case Dene: {
            int len = length / 2;
            for (int i = 0; i < len; i++)
                deleteSegment();
            score += DeneScore;
            (*pDene)--;
            break;
        }
        default:
            exit(-1);
    }

    if (length <= 1)
        return false;
    return true;
}


Direction Snake::BFS() {
    Point target = findClosestCoordinate();
    if (target.row == INVALID_ROW || target.col == INVALID_COLUMN)
        return head->direction;

    int mat[gridRow][gridCol];
    for (int i = 0; i < gridRow; i++) {
        for (int j = 0; j < gridCol; j++) {
            mat[i][j] = (map[i][j] == GridWall || map[i][j] == SnakeHead || map[i][j] == SnakeBody);
        }
    }
    mat[target.row][target.col] = 0;
    mat[head->coordinate.Y][head->coordinate.X] = 0;

    Point nextStep = findNextStep(mat, head->coordinate.Y, head->coordinate.X, target.row, target.col);
    if (nextStep.row == INVALID_ROW || nextStep.col == INVALID_COLUMN)
        return head->direction;

    // 确定新方向
    if (nextStep.row < head->coordinate.Y)
        return Up;
    if (nextStep.row > head->coordinate.Y)
        return Down;
    if (nextStep.col < head->coordinate.X) 
        return Left;
    if (nextStep.col > head->coordinate.X) 
        return Right;

    return head->direction;
}

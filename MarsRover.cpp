// Mars Rover Programming Exercise

#include <bits/stdc++.h>
using namespace std;

enum class Direction
{
    N,
    E,
    S,
    W
};

class MarsRover
{
private:
    int GridX;
    int GridY;
    bool obstacleDetected = false;
    int x;
    int y;
    Direction direction;
    unordered_set<string> obstacles;

public:
    MarsRover(int x, int y, Direction direction) : x(x), y(y), direction(direction) {}

    void GridSize(int row, int col);

    void addObstacle(int x, int y);

    bool isValidPosition(int x, int y);

    void move();

    void rotate(char rotation);

    string getPosition();

private:
    string directionToString(Direction dir)
    {
        switch (dir)
        {
        case Direction::N:
            return "N";
        case Direction::E:
            return "E";
        case Direction::S:
            return "S";
        case Direction::W:
            return "W";
        default:
            return "Unknown";
        }
    }
};

void MarsRover::addObstacle(int x, int y)
{
    obstacles.insert(to_string(x) + ":" + to_string(y));
}

void MarsRover::rotate(char rotation)
{
    if (rotation == 'L')
    {
        direction = Direction(((int)direction + 3) % 4);
    }
    else if (rotation == 'R')
    {
        direction = Direction(((int)direction + 1) % 4);
    }
}

void MarsRover::move()
{
    int nextX = x;
    int nextY = y;
    switch (direction)
    {
    case Direction::N:
        nextY++;
        break;
    case Direction::E:
        nextX++;
        break;
    case Direction::S:
        nextY--;
        break;
    case Direction::W:
        nextX--;
        break;
    }

    // Check for obstacles and boundary conditions
    string nextPosition = to_string(nextX) + ":" + to_string(nextY);
    if (obstacles.find(nextPosition) != obstacles.end())
    {
        obstacleDetected = true;
    }
    if (obstacles.find(nextPosition) == obstacles.end() && isValidPosition(nextX, nextY))
    {
        x = nextX;
        y = nextY;
    }
}

string MarsRover::getPosition()
{
    return "Final position of Mars Rover is (" + to_string(x) + "," + to_string(y) + ") facing " +
           directionToString(direction) + (obstacleDetected ? " and Obstacles detected" : " and no obstacles detected");
}

bool MarsRover::isValidPosition(int x, int y)
{
    return x >= 0 && x <= GridX && y >= 0 && y <= GridY;
}

void MarsRover::GridSize(int row, int col)
{
    if (row <= 0 || col <= 0)
    {
        throw invalid_argument("Grid size must be positive");
    }
    GridX = row;
    GridY = col;
}

void FindPosition(MarsRover &rover, string commands)
{
    for (char command : commands)
    {
        if (command == 'L' || command == 'R')
        {
            rover.rotate(command);
        }
        else if (command == 'M')
        {
            rover.move();
        }
        else
        {
            throw invalid_argument("Invalid command: " + string(1, command));
        }
    }
}

int main()
{
    try
    {
        MarsRover rover(0, 0, Direction::N);
        rover.GridSize(10, 10);
        rover.addObstacle(2, 2);
        rover.addObstacle(3, 5);

        string commands = "MMRMLM";
        FindPosition(rover, commands);

        cout << rover.getPosition() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown error occurred" << endl;
    }

    return 0;
}

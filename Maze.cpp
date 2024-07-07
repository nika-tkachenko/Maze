#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Cell {
    WALL,
    ROAD,
    ENTRANCE,
    EXIT,
    TRAP,
    TREASURE
};

struct Position {
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class Maze {
public:
    Maze(int width, int height) : width(width), height(height), maze(height, vector<Cell>(width, WALL)) {
        srand(time(0));
        generateMaze();
    }

    void printMaze() const {
        for (const auto& row : maze) {
            for (const auto& cell : row) {
                switch (cell) {
                case WALL: cout << "#"; break;
                case ROAD: cout << " "; break;
                case ENTRANCE: cout << "E"; break;
                case EXIT: cout << "X"; break;
                case TRAP: cout << "T"; break;
                case TREASURE: cout << "$"; break;
                }
            }
            cout << endl;
        }
    }

private:
    int width, height;
    vector<vector<Cell>> maze;
    Position entrance, exit;

    void generateMaze() {
        // Starting point (top left corner)
        entrance = { 0, 1 };
        exit = { height - 1, width - 2 };

        // Set input and output
        maze[entrance.x][entrance.y] = ENTRANCE;
        maze[exit.x][exit.y] = EXIT;

        // Generate a maze using DFS
        stack<Position> stack;
        stack.push({ 1, 1 });
        maze[1][1] = ROAD;

        while (!stack.empty()) {
            Position current = stack.top();
            vector<Position> neighbors;

            if (current.x > 1 && maze[current.x - 2][current.y] == WALL) {
                neighbors.push_back({ current.x - 2, current.y });
            }
            if (current.x < height - 2 && maze[current.x + 2][current.y] == WALL) {
                neighbors.push_back({ current.x + 2, current.y });
            }
            if (current.y > 1 && maze[current.x][current.y - 2] == WALL) {
                neighbors.push_back({ current.x, current.y - 2 });
            }
            if (current.y < width - 2 && maze[current.x][current.y + 2] == WALL) {
                neighbors.push_back({ current.x, current.y + 2 });
            }

            if (!neighbors.empty()) {
                Position next = neighbors[rand() % neighbors.size()];
                maze[(current.x + next.x) / 2][(current.y + next.y) / 2] = ROAD;
                maze[next.x][next.y] = ROAD;
                stack.push(next);
            }
            else {
                stack.pop();
            }
        }

        // Adding traps and treasure
        addTraps();
        addTreasure();
    }

    void addTraps() {
        int trapCount = rand() % 6;
        while (trapCount > 0) {
            int x = rand() % height;
            int y = rand() % width;
            if (maze[x][y] == ROAD) {
                maze[x][y] = TRAP;
                trapCount--;
            }
        }
    }

    void addTreasure() {
        bool treasureAdded = false;
        while (!treasureAdded) {
            int x = rand() % height;
            int y = rand() % width;
            if (maze[x][y] == ROAD) {
                maze[x][y] = TREASURE;
                treasureAdded = true;
            }
        }
    }
};

int main() {
    int width, height;
    cout << "Enter width of the maze: ";
    cin >> width;
    cout << "Enter height of the maze: ";
    cin >> height;

    Maze maze(width, height);
    maze.printMaze();

    return 0;
}

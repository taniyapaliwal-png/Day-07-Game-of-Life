#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

const int ROWS = 20;
const int COLS = 40;

void printGrid(int grid[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == 1) {
                cout << "# ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) 
                continue;

            int r = row + dr;
            int c = col + dc;

            if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                count += grid[r][c];
            }
        }
    }       
    return count;
}       

void nextGeneration(int current[ROWS][COLS], int next[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            int n = countNeighbors(current, r, c);

            if (current[r][c] == 1) {
                if (n == 2 || n == 3) {
                    next[r][c] = 1;
                } else {
                    next[r][c] = 0;
                }
            } else {
                if (n == 3) {
                    next[r][c] = 1;
                } else {
                    next[r][c] = 0;
                }           
            }
        }
    }
}
void copyGrid(int from[ROWS][COLS], int to[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            to[r][c] = from[r][c];
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0};
    int newGrid[ROWS][COLS] = {0};

    // Blinker: three cells in a row 
    grid[10][19] = 1;
    grid[10][20] = 1;       
    grid[10][21] = 1;

    for (int gen = 0; gen < 100; gen++) {
        system("clear");
        cout << "Generation: " << gen << endl;
        printGrid(grid);

        nextGeneration(grid, newGrid);
        copyGrid(newGrid, grid);

        this_thread::sleep_for(chrono::milliseconds(200));
    }
    return 0;
}
grid[1][2] = 1;
grid[2][3] = 1;
grid[3][1] = 1;
grid[3][2] = 1;
grid[3][3] = 1;
# Conway's Game of Life in C++

A terminal-based simulation of Conway's Game of Life, written in C++ using only core language basics: 2D arrays, loops, conditionals and functions.

## What is the Game of Life?

The Game of Life is a **cellular automaton** invented by mathematician John Conway in 1970. It is not a game you play. You choose a starting pattern, then watch it evolve on its own.

The world is a grid of cells, each either **alive** or **dead**. Every generation, all cells update at the same time based on their 8 neighbors:

1. A live cell with **fewer than 2** live neighbors dies (underpopulation).
2. A live cell with **2 or 3** live neighbors survives.
3. A live cell with **more than 3** live neighbors dies (overpopulation).
4. A dead cell with **exactly 3** live neighbors becomes alive (reproduction).

From these simple rules, complex behavior emerges: patterns that oscillate, patterns that crawl across the grid, and patterns that create new patterns.

## Features

- 20 x 40 grid displayed in the terminal (`#` = alive, `.` = dead)
- Animated generations with a generation counter
- Starting patterns: **blinker** (oscillator) and **glider** (spaceship)
- Simultaneous updates using two grids, so cells never read half-updated data

## Getting started

### Requirements

- A C++ compiler (`g++` or `clang++`)
- A terminal (macOS or Linux)

### Build and run

```bash
g++ life.cpp -o life
./life
```

The simulation runs for 100 generations. Press `Ctrl + C` to stop it early.

> **Windows users:** replace `system("clear");` with `system("cls");` in the code.

## How it works

The program is built from four small functions:

| Function | Purpose |
|---|---|
| `printGrid` | Prints the grid, using `#` for alive cells and `.` for dead ones |
| `countNeighbors` | Counts the live cells around a given cell, ignoring positions outside the grid |
| `nextGeneration` | Applies the rules to every cell, reading from the current grid and writing to a new one |
| `copyGrid` | Copies the new generation back into the main grid |

**Key idea: two grids.** All cells must update at the same moment. If the program changed cells in place, cells processed later would see already-updated neighbors and get the wrong count. So each generation is read from one grid and written to another, then copied back.

**Edges.** Cells outside the grid are treated as dead, so patterns stop or settle when they reach a border.

## Try these patterns

**Blinker** (flips between horizontal and vertical forever):

```cpp
grid[5][5] = 1;
grid[5][6] = 1;
grid[5][7] = 1;
```

**Glider** (crawls diagonally toward the bottom-right corner):

```cpp
grid[1][2] = 1;
grid[2][3] = 1;
grid[3][1] = 1;
grid[3][2] = 1;
grid[3][3] = 1;
```

## What I learned
 Being a person learning C++ and exploring different things sure this project was overwhelming at first. 
 I picked up:
# 2D arrays: A 2D array is like a table with rows and columns. I used one loop inside another loop to visit every cell.
# Functions: Instead of writing everything in one giant mess, I split the code into small functions. It's way easier to fix things this way.
# Counting neighbors was the hardest part. I had to check the 8 cells around each cell and make sure I didn't go outside the grid.
# Why two grids? If you change the grid while you're still reading it, the counts get messed up. So I read from the old grid and write into a new one.
# Debugging: I got errors and confusing output along the way. I learned to read the error message, check my spelling, and run the program in the terminal.
# The coolest part: Just 3 simple rules make patterns that look alive. I didn't code the glider to move. The rules make it move by themselves.



## Roadmap

- [ ] Random starting patterns
- [ ] Population counter
- [ ] Wrap-around (toroidal) edges
- [ ] Stop automatically when the grid stops changing
- [ ] Pattern menu (blinker, glider, glider gun, random)
- [ ] Colors using ANSI escape codes
- [ ] Rewrite the grid using `vector<vector<int>>`

## Project structure

```
.
├── life.cpp
└── README.md
```

## Acknowledgements

- Rules by [John Conway](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), 1970

## Author
 [GitHub](https://github.com/your-taniyapaliwal-png)
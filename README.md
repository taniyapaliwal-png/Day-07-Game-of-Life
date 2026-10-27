 <div align="center">

<img src="https://capsule-render.vercel.app/api?type=venom&height=180&color=gradient&customColorList=6,12,20,24,30&text=GAME%20OF%20LIFE&fontSize=48&fontColor=ffffff&animation=twinkling&stroke=111111&strokeWidth=2" width="100%" alt="Retro arcade Game of Life banner"/>

# 🎮 INSERT COIN TO EVOLVE

**A tiny C++ experiment where pixels live, die, and do their own thing.**

`[ C++ ]` · `[ 20 × 40 WORLD ]` · `[ 100 GENERATIONS ]`

<br/>

<img src="https://readme-typing-svg.demolab.com?font=Press+Start+2P&size=10&duration=2500&pause=800&color=FF4FA3&center=true&vCenter=true&width=600&height=45&lines=HELLO%2C+PLAYER+ONE!;READY%3F+SET+YOUR+CELLS.;LET+THE+PIXELS+LIVE!" alt="Retro game intro"/>

</div>

---

## 🕹️ PLAYER 1 — WHAT IS THIS?

Imagine a tiny world made of squares.

Some are alive. Some aren't. You press play, and every square checks its neighbors before deciding what happens next.

That's **Conway's Game of Life**, a cellular automaton created by mathematician John Conway in 1970. You don't control individual cells once the simulation starts. You just watch the chaos unfold.

And somehow, four simple rules can create patterns that move, blink, grow, and disappear.

**No fancy game engine. No graphics library. Just C++ fundamentals and a grid.**

## 👾 THE WORLD

<div align="center">

### `LEVEL 01 — THE GRID`

```text
. . . . . . . . . . . . . . . .
. . . . . # # # . . . . . . . .
. . . . . . # . . . . . . . . . .
. . . . . # # # . . . . . . . . .
. . . . . . . . . . . . . . . . .
. . # . . . . . . . . . # . . . .
. . . # . . . . . . . # . . . . .
. # # # . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . .
```

`#` = ALIVE  `.` = DEAD

</div>

<sub>Just a sample grid for illustration. The program uses a 20 × 40 grid and animates its generations in the terminal.</sub>

## 🎯 THE FOUR RULES

<details>
<summary>🩷 1UP — UNDERPOPULATION</summary>

A living cell with fewer than two living neighbors dies.

Too lonely. Game over for that cell.

</details>

<details>
<summary>💚 2UP — SURVIVAL</summary>

A living cell with two or three living neighbors survives.

Perfect neighborhood. Keep going!

</details>

<details>
<summary>💛 3UP — OVERPOPULATION</summary>

A living cell with more than three living neighbors dies.

Too crowded in here.

</details>

<details>
<summary>🩵 EXTRA LIFE — REPRODUCTION</summary>

A dead cell with exactly three living neighbors becomes alive.

New pixel unlocked!

</details>

The catch? Every cell updates at the same time. A cell doesn't get to see its neighbors' already-updated states.

That's why the program uses **two grids** — one to read from and one to write the next generation into.

## 🌀 CHOOSE YOUR CHARACTER

<div align="center">

| 🪲 BLINKER | 🚀 GLIDER |
|---|---|
| The tiny oscillator | The travelling pattern |
| ```text\n. . . . .\n. # # # .\n. . . . .``` | ```text\n. # . . .\n. . # . .\n# # # . .``` |
| Flips between two states | Moves diagonally as generations evolve |

</div>

Want to spawn a different pattern? Change the starting cells in `life.cpp`.

**Blinker power-up:**

```cpp
grid[5][5] = 1;
grid[5][6] = 1;
grid[5][7] = 1;
```

**Glider power-up:**

```cpp
grid[1][2] = 1;
grid[2][3] = 1;
grid[3][1] = 1;
grid[3][2] = 1;
grid[3][3] = 1;
```

These snippets show how to set the patterns up; they are not a separate interactive pattern selector.

## 🧃 START THE GAME

### What you need

- `g++` or `clang++`
- macOS or Linux terminal

### 1. Compile

```bash
g++ life.cpp -o life
```

### 2. Play

```bash
./life
```

That's it. The simulation runs for **100 generations**. Press `Ctrl + C` to stop it early.

<details>
<summary>🪟 Playing on Windows?</summary>

If the code clears the terminal using `system("clear");`, change it to `system("cls");` for Windows before compiling with your C++ compiler.

</details>

## 🧩 HOW I BUILT IT

This was one of my early C++ projects, and honestly, the neighbor-counting part took the most thinking.

I split the program into four functions:

| Function | Job |
|---|---|
| `printGrid` | Draws the current world in the terminal |
| `countNeighbors` | Checks the eight surrounding cells |
| `nextGeneration` | Applies the rules and calculates the next state |
| `copyGrid` | Copies the next state back into the main grid |

The trickiest bug to avoid was updating cells too early. If a cell changed before its neighbors were counted, the next generation could become incorrect.

Using two grids fixed that problem and helped me understand how state updates work.

### 🧠 Skills unlocked

- Nested loops and 2D arrays
- Functions and code organization
- Boundary checks and neighbor counting
- Separating current state from next state
- Debugging and testing in the terminal

The coolest discovery? **I never told the glider to move.** Its movement emerges from the rules.

## 🛠️ NEXT LEVEL — IDEAS FOR LATER

These are future upgrades, not features in the current version.

- [ ] 🎲 Random starting cells
- [ ] 🔢 Living-cell population counter
- [ ] 🌍 Wrap-around edges
- [ ] ⏸️ Stop when the grid stops changing
- [ ] 🎛️ Pattern-selection menu
- [ ] 🌈 Coloured terminal output
- [ ] 🧱 Dynamic grid with `vector<vector<int>>`

## 📁 GAME FILES

```text
game-of-life/
├── life.cpp
└── README.md
```

## 🏆 CREDITS

The original Game of Life was devised by [John Conway](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) in 1970.

This version is my own learning project, built to explore C++ basics through something visual and fun.

---

<div align="center">

### 🌟 THANKS FOR PLAYING!

**Made by [Taniya Paliwal](https://github.com/taniyapaliwal-png)**

*Now go make some pixels come alive.*

`GAME OVER? NAH. JUST ANOTHER GENERATION.`

<img src="https://capsule-render.vercel.app/api?type=waving&height=100&section=footer&color=0:FF4FA3,50:FFD93D,100:6C63FF" width="100%" alt="Colourful arcade footer"/>

</div>

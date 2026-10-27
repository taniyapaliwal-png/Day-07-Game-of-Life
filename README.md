 <div align="center">

<!-- ARCADE HEADER -->
<img src="https://capsule-render.vercel.app/api?type=waving&height=230&color=0:09090f,35:241052,70:6d28d9,100:00f5d4&text=GAME%20OF%20LIFE&fontColor=ffffff&fontSize=48&fontAlignY=38&desc=ONE%20GRID.%20FOUR%20RULES.%20INFINITE%20POSSIBILITIES.&descSize=13&descAlignY=58&animation=fadeIn" width="100%" alt="Game of Life — neon arcade banner"/>

<img src="https://readme-typing-svg.demolab.com?font=Courier+Prime&weight=700&size=18&duration=2600&pause=800&color=00F5D4&center=true&vCenter=true&width=600&lines=INITIALIZING+CELLULAR+AUTOMATON...;LOADING+GENERATION+001...;LIFE+EMERGES+FROM+SIMPLE+RULES.;SYSTEM+ONLINE+%E2%80%94+LET+IT+EVOLVE." alt="Animated terminal messages"/>

<br/>

<a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life"><img src="https://img.shields.io/badge/GENRE-CELLULAR_AUTOMATON-6d28d9?style=for-the-badge&labelColor=09090f" alt="Cellular automaton"/></a>
<img src="https://img.shields.io/badge/BUILT_WITH-C%2B%2B-00f5d4?style=for-the-badge&labelColor=09090f" alt="Built with C++"/>
<img src="https://img.shields.io/badge/RENDER-TERMINAL-ff4ecd?style=for-the-badge&labelColor=09090f" alt="Terminal rendering"/>
<img src="https://img.shields.io/badge/STATUS-PLAYABLE-7CFC98?style=for-the-badge&labelColor=09090f" alt="Playable project"/>

<br/><br/>

**[ ▸ ENTER THE SIMULATION ](#-boot-up)** &nbsp; • &nbsp; **[ HOW IT WORKS ](#-the-rules-of-life)** &nbsp; • &nbsp; **[ SOURCE CODE ](#-inside-the-machine)**

</div>

---

<div align="center">

## `SYSTEM MESSAGE // 001`

**You don't control the cells. You create the world — and watch life happen.**

</div>

Welcome to my C++ implementation of **Conway's Game of Life** — a terminal-based cellular automaton where a few simple rules produce surprisingly complex behavior.

No enemies. No score. No player movement.

Just a grid of living and dead cells, evolving one generation at a time.

```text
┌──────────────────────────────────────────┐
│           LIFE SIMULATION v1.0           │
│                                          │
│  GENERATION: 0042                        │
│  WORLD:      20 × 40                     │
│  ALIVE:      #                           │
│  DEAD:       .                           │
│                                          │
│  . . . . . . . . . . . . . . . . . . . │
│  . . . . . # # # . . . . . . . . . . . │
│  . . . . . . # . . . . . . . . . . . . │
│  . . . . . # # # . . . . . . . . . . . │
│  . . . . . . . . . . . . . . . . . . . │
│                                          │
│  STATUS: EVOLVING...                     │
└──────────────────────────────────────────┘
```

<sub>Illustrative terminal mockup — the actual program displays its evolving grid and generation counter.</sub>

## `01` // THE RULES OF LIFE

Every cell checks its eight neighboring cells. Then the entire grid updates simultaneously.

<details>
<summary>🟢 RULE 01 — UNDERPOPULATION</summary>

A living cell with fewer than two living neighbors dies.

Too few neighbors, and life cannot sustain itself.

</details>

<details>
<summary>🟣 RULE 02 — SURVIVAL</summary>

A living cell with two or three living neighbors survives into the next generation.

The balance is just right.

</details>

<details>
<summary>🔴 RULE 03 — OVERPOPULATION</summary>

A living cell with more than three living neighbors dies.

Too many neighbors, too much competition.

</details>

<details>
<summary>🔵 RULE 04 — REPRODUCTION</summary>

A dead cell with exactly three living neighbors becomes alive.

A new cell enters the simulation.

</details>

<div align="center">

**FOUR RULES. ZERO RANDOM DECISIONS DURING EVOLUTION. EMERGENT COMPLEXITY.**

</div>

## `02` // WATCH THE PATTERNS

<div align="center">

| PATTERN | BEHAVIOR | WHAT HAPPENS |
|:---:|---|---|
| `BLINKER` | Oscillator | Flips between horizontal and vertical |
| `GLIDER` | Spaceship | Moves diagonally across the grid |

</div>

### The Blinker

```text
Generation A          Generation B

. . . . .             . . . . .
. . # . .             . # . . .
. . # . .             . # # # .
. . # . .             . # . . .
. . . . .             . . . . .
```

### The Glider

A five-cell pattern that moves diagonally through the grid as generations evolve.

```text
. # . . .       . . # . .       . . . . .
. . # . .  →    . . . # .  →    . # . # .
# # # . .       . # # # .       . . # # .
. . . . .       . . . . .       . # # . .
```

<sub>Conceptual illustrations of pattern evolution, not exact consecutive frames from the program.</sub>

## `03` // BOOT UP

### Requirements

- A C++ compiler (`g++` or `clang++`)
- A terminal on macOS or Linux
- Git (optional, for cloning the repository)

### Compile the simulation

```bash
g++ life.cpp -o life
```

### Launch the simulation

```bash
./life
```

The simulation runs for **100 generations**. Press `Ctrl + C` to stop it early.

<details>
<summary>🪟 Windows setup</summary>

If your source code uses `system("clear");`, replace it with `system("cls");` for a Windows terminal, then compile using your installed C++ compiler.

</details>

## `04` // INSIDE THE MACHINE

The project uses four functions to keep the simulation organized.

| FUNCTION | RESPONSIBILITY |
|---|---|
| `printGrid` | Renders the grid with `#` for living cells and `.` for dead cells |
| `countNeighbors` | Counts living neighbors while respecting grid boundaries |
| `nextGeneration` | Applies the four rules to every cell and writes the next state |
| `copyGrid` | Copies the calculated generation back into the main grid |

### The two-grid system

This is the core idea behind the implementation.

```text
      CURRENT GRID
           │
           ▼
   COUNT EACH CELL'S
      NEIGHBORS
           │
           ▼
     APPLY THE RULES
           │
           ▼
      NEXT GRID
           │
           ▼
      COPY BACK
           │
           ▼
   NEXT GENERATION
```

Why not update the same grid directly?

Because cells processed earlier would change the neighbors seen by cells processed later. That would make the result depend on iteration order.

By reading from one grid and writing to another, every cell uses the same generation as its input.

**The entire generation advances together.**

### What happens at the edges?

Cells outside the grid are treated as dead. The grid does not wrap around, so patterns can disappear or settle when they reach a boundary.

## `05` // EXPERIMENT WITH THE CODE

Want to create your own starting pattern? Set individual cells to `1` before the simulation starts.

<details>
<summary>⚡ SPAWN A BLINKER</summary>

```cpp
grid[5][5] = 1;
grid[5][6] = 1;
grid[5][7] = 1;
```

Three adjacent living cells form an oscillator.

</details>

<details>
<summary>🚀 SPAWN A GLIDER</summary>

```cpp
grid[1][2] = 1;
grid[2][3] = 1;
grid[3][1] = 1;
grid[3][2] = 1;
grid[3][3] = 1;
```

Five living cells form a pattern that travels diagonally.

</details>

Try changing the starting coordinates, combining patterns, or creating a completely different arrangement.

Small changes to the initial state can produce very different outcomes.

## `06` // DEVELOPER LOG

This was one of my early explorations into C++. It looked simple at first, but getting the grid logic right took more thought than expected.

**What I learned along the way:**

- **2D arrays:** Representing a world as rows and columns, and using nested loops to visit every cell.
- **Functions:** Breaking the program into smaller, reusable pieces instead of writing everything in one giant block.
- **Neighbor counting:** Checking all eight surrounding positions without accessing cells outside the grid.
- **State management:** Understanding why the current and next generations must be stored separately.
- **Debugging:** Reading compiler errors, checking logic, and testing changes in the terminal.
- **Emergent behavior:** Seeing how a few simple rules can create patterns that appear to move, oscillate, or disappear.

The coolest part? I didn't program the glider to move. **The rules made it move.**

## `07` // FUTURE UPDATES

The simulation works in its current form. These are ideas for future versions, not features already implemented.

- [ ] Random starting patterns
- [ ] Population counter
- [ ] Wrap-around (toroidal) edges
- [ ] Stop automatically when the grid stops changing
- [ ] Pattern selection menu — blinker, glider, glider gun, random
- [ ] ANSI terminal colors
- [ ] Dynamic grid using `vector<vector<int>>`

## `08` // FILE SYSTEM

```text
GAME-OF-LIFE/
├── life.cpp       # Simulation logic
└── README.md      # Documentation
```

## `09` // CREDITS

Conway's Game of Life was devised by mathematician **John Horton Conway** in 1970.

Learn more: [Wikipedia — Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00f5d4,50:6d28d9,100:09090f&height=120&section=footer" width="100%" alt="Neon simulation footer"/>

### `SIMULATION COMPLETE // YOUR TURN TO EXPERIMENT`

**Made by [Taniya Paliwal](https://github.com/taniyapaliwal-png)**

<sub>Built with C++ fundamentals, curiosity, and a lot of neighbor counting.</sub>

<br/>

`[ RESTART ]` &nbsp; `./life`

</div>

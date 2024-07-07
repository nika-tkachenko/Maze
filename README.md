# Maze Generator for 2D Game

This project is a console-based application designed to generate 2D mazes for a game. The mazes are represented as matrices with different cell types, including an entrance, an exit, roads, walls, traps, and treasures. The application ensures that there is always a path from the entrance to the exit, taking into account the possibility of traps.

## Features

- **Entrance:** Only one entrance, located on an outer side of the maze.
- **Exit:** Only one exit, located on an outer side of the maze.
- **Road:** Cells that the player can pass through.
- **Wall:** Cells that the player cannot pass through.
- **Trap (Optional):** Cells that the player can pass through, but passing through three traps will result in the player's death. There can be 0-5 traps in a maze.
- **Treasure (Optional):** A cell containing a treasure. There can be 0-1 treasures in a maze.

## Rules

- The maze must have at least one path from the entrance to the exit.
- If traps are included, the path must ensure that the player will not die from traps.
- The treasure must be reachable.

## Getting Started

### Prerequisites

- C++ compiler

Вот формат для GitHub:

---

## Running the Application

1. Clone the repository:

2. Compile the code:
   
3. Run the application:
  
4. Enter the width and height of the maze when prompted.

### Example

```
Enter width of the maze: 10
Enter height of the maze: 10
```

The output will be a 10x10 maze with different cell types represented by different characters:

- `#` for walls
- ` ` for roads
- `E` for the entrance
- `X` for the exit
- `T` for traps
- `$` for the treasure

## Efficiency and Complexity

The maze generation algorithm is based on Depth-First Search (DFS), which ensures the creation of a solvable maze with a clear path from the entrance to the exit. The complexity of the algorithm is O(N), where N is the number of cells in the maze. This is because each cell is visited once during the maze generation process.

The trap and treasure placement algorithms also run in O(N) time, as they involve scanning and modifying the maze matrix.

## Code Explanation

### Maze Generation

The maze is generated using a randomized DFS algorithm. The maze starts with all walls, and the DFS algorithm carves out roads by visiting each cell once and creating paths between them.

### Trap and Treasure Placement

Traps and treasures are placed after the maze is generated. The algorithm ensures that the traps do not block the path from the entrance to the exit.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request with your improvements.

# Tower of Hanoi (C Implementation)

This project is a console-based implementation of the classic **Tower of Hanoi** puzzle written in C.  
The game allows the user to manually type the moves between the three towers until all disks are moved to the target tower following the rules of the puzzle.

## Project Structure

- `hanoi_tower.c` – Main source file containing the entire game logic and user interaction.

## Technologies and Concepts Used

- **Language:** C
- **Standard libraries:**
  - `<stdio.h>` for input and output
  - `<stdlib.h>` (reserved for general utilities)
  - `<string.h>` for dealing with strings (e.g., `strlen` and formatted input)
- **Key C concepts practiced:**
  - Arrays (`int A[5], B[5], C[5]`) to represent the three towers
  - Pointers and pointer arithmetic to manipulate the top elements of each tower
  - Conditionals (`if`, `else if`, `else`) to validate moves
  - Loops (`while`, `for`) to control the game flow and print the board
  - Basic input validation with `scanf` and checks on the entered command
  - Game logic implementation (enforcing Tower of Hanoi rules)

## Game Rules (Tower of Hanoi)

The classic Tower of Hanoi puzzle consists of:

- Three pegs (here named **A**, **B**, and **C**)
- A stack of disks of different sizes, initially all placed on peg **A**
- The goal is to move the entire stack from peg **A** to peg **C**, following these rules:
  1. Only one disk can be moved at a time.
  2. Each move consists of taking the **top disk** from one peg and placing it on top of another peg.
  3. You **cannot** place a larger disk on top of a smaller disk.

In this implementation, the game uses **5 disks** with values from `1` (smallest) to `5` (largest), initially placed on tower **A**.

## How the Program Works (Internals)

### Representation of Towers

- Three arrays of integers represent the towers:
  - `A[5]` – initially `{1, 2, 3, 4, 5}` (all disks start here)
  - `B[5]` – initially `{0, 0, 0, 0, 0}`
  - `C[5]` – initially `{0, 0, 0, 0, 0}`

- Pointers keep track of the current “top” of each tower:
  - `int *pontA = A;`
  - `int *pontB = NULL;`
  - `int *pontC = NULL;`

As the user performs moves, these pointers and arrays are updated to simulate taking a disk from one tower and placing it on another.

### Main Game Loop

- The game runs inside a `while` loop until the puzzle is solved (all disks moved to tower **C**) or the user quits.
- At each iteration:
  1. The current state of the three towers is printed, showing the content of A, B, and C.
  2. The user is asked to type a move (e.g., `AB`, `BC`, `CA`, etc.).
  3. The program validates the move:
     - Checks if the origin tower has at least one disk.
     - Checks that the move does not place a larger disk on top of a smaller one.
  4. If the move is valid, the program updates the arrays and pointers, and increments the move counter.
  5. If the move is invalid, it prints an error message: `"Jogada Inválida!"`.

- The loop stops when the final configuration is reached (all disks on tower **C**) and prints a success message.

## User Controls

At the start, the program prints instructions for the valid commands. You can type:

- `AB` – move the top disk from tower **A** to tower **B**
- `AC` – move the top disk from tower **A** to tower **C**
- `BA` – move the top disk from tower **B** to tower **A**
- `BC` – move the top disk from tower **B** to tower **C**
- `CA` – move the top disk from tower **C** to tower **A**
- `CB` – move the top disk from tower **C** to tower **B**

Special command:

- `10` – quit the game (the program prints that you gave up and exits)

Any other input is treated as an invalid move and the program will show `"Jogada Inválida!"`.

## How to Compile and Run

### Requirements

- A C compiler (for example, `gcc`)
- A terminal (Linux, WSL, or similar)

### Compilation (Linux/WSL)

From the folder where `hanoi_tower.c` is located, run:

```bash
gcc -Wall -Wextra -std=c11 -o hanoi_tower hanoi_tower.c
```

This will generate an executable named hanoi_tower; run the program with ./hanoi_tower

## Learning Outcomes

By building this project, the following skills were practiced:

- Implementing a classic puzzle (Tower of Hanoi) manually, without recursion
- Using arrays and pointers together to simulate stacks
- Performing pointer arithmetic to access and move elements between arrays
- Validating user input and enforcing game rules
- Structuring a C program with a main game loop and repeated user interaction

## Possible Improvements

Judging from nowadays (Nov - 2025)
Future enhancements could include:

- Allowing a variable number of disks (instead of being fixed at 5)
- Counting and displaying the minimum optimal number of moves versus the user’s moves
- Adding input options for:
  - Choosing the number of disks
  - Restarting the game without closing the program
- Improving the visual representation of the towers in the console
- Refactoring the code to reduce repetition using helper functions
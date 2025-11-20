# C Projects – Beginner Collection

This repository contains a collection of small C console projects that I built while learning the language and strengthening my problem-solving skills in 2023.

Even though these are simple projects, they show my first contact with important concepts such as pointers, dynamic memory allocation, data structures, recursion, imput validation, menu-driven interfaces, number base conversions and more.

## Projects

- [Hanoi Tower](./hanoi_tower)  
  Interactive console version of the Tower of Hanoi puzzle using arrays and pointers to represent the three towers.

- [Zoo Management System](./zoo_system)  
  Small management system for a zoo, using dynamic memory allocation and a 3D data structure (sectors → cages → animals).

- [Binary Calculator](./binary_calculator)  
  A menu-driven calculator that works with binary numbers and supports arithmetic operations and base conversions.

## Technologies

- Language: **C (C99/C11)**
- Standard Library: `stdio.h`, `stdlib.h`, `string.h`, etc.
- Typical environment:
  - **Linux/WSL** (Ubuntu)
  - **GCC** as the C compiler
  - **Visual Studio Code** as the main editor/IDE

All projects are console-based and can be compiled with any C compiler that supports standard C.

## How to Build and Run

Below is a generic example using `gcc` on Linux/WSL.  
Each project has its own README with more details.

```bash
# Example: compile and run the Hanoi Tower project
cd hanoi_tower
gcc hanoi_tower.c -o hanoi_tower
./hanoi_tower

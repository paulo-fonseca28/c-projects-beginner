# Zoo Management System (C Implementation)

This project is a console-based **zoo management system** written in C.  
It allows the user to manage sectors, cages, and animals in a zoo, using dynamic memory allocation and a menu-driven interface.

The program supports:

- Registering sectors and cages
- Inserting animals into cages of specific sectors
- Finding the heaviest animal in a sector
- Adding and removing sectors dynamically
- Finding the tallest animal in a sector

---

## Project Structure

- `zoo_system.c` – Single source file containing:
  - Data structure definitions
  - Dynamic memory allocation and deallocation
  - Menu handling
  - All operations for managing sectors, cages, and animals

---

## Data Structures

### `info_animal` structure

```c
typedef struct info_animal{
    int codigo;
    char nome[50];
    float peso;
    float altura;
    char especie[50];
} info_animal;

## Zoo Representation

The zoo is represented by a three-level pointer:

```c
info_animal ***zoologico;
```

Logically, it works as:

```c
zoologico[setor][jaula][animal]
```

Other important variables:

* `int numSetores;` – Number of sectors in the zoo
* `int numJaulas;` – Number of cages per sector
* `int numAnimais;` – Maximum number of animals per cage
* `char **nomeSetores;` – Dynamic array of sector names

Memory is allocated dynamically based on the quantities informed by the user in the initialization step.

---

## Features and Menu Options

At runtime, the program presents the following menu:

```text
Digite '0' para sair do programa.
1- Inicializacao do sistema:
2- Catalogo de setores:
3- Inserir animais em uma jaula de um setor:
4- Animal mais pesado de um dado setor:
5- Inserir novo setor:
6- Remover setor:
7- Buscar animal mais alto de um setor especifico:
```

### Option 1 – System Initialization

Asks the user to input:

* Number of sectors (`numSetores`)
* Number of cages per sector (`numJaulas`)
* Number of animals per cage (`numAnimais`)

Allocates:

* `zoologico` as a 3D structure with dimensions:

  * `numSetores × numJaulas × numAnimais`
* `nomeSetores` as an array of strings, one name per sector

Uses `malloc`/`calloc` to allocate the nested arrays of `info_animal`.

This step must be performed before using most of the other options.

### Option 2 – Sector Catalog

For each sector, prompts the user to enter a name (for example, "Mamíferos", "Répteis", "Aves", etc.).

Stores each sector name in the corresponding position of `nomeSetores[i]`.

These names are later used to locate sectors by name in other menu options.

### Option 3 – Insert Animals into a Cage of a Sector

Asks the user for:

* Sector name (string)
* Cage number (from `1` to `numJaulas`)

Searches for the sector by comparing the input name with the stored `nomeSetores`.

If the sector exists and the cage number is valid:

For each animal slot in that cage (from `0` to `numAnimais - 1`), the program asks:

* `codigo`
* `nome`
* `peso`
* `altura`
* `especie`

These values are stored in:

```c
zoologico[setorEncontrado][numJaula - 1][i]
```

If the sector name or cage number is invalid, an error message is printed and the operation is aborted.

### Option 4 – Heaviest Animal in a Sector

Asks for the sector name and searches for the sector by name.

Iterates over all cages and all animals in that sector:

* Keeps track of the maximum `peso` found
* Stores the name of the heaviest animal

At the end:

* If at least one animal with `peso > 0` is found, prints:

  * Name of the heaviest animal
  * Its weight
* Otherwise, prints that there are no animals in that sector.

### Option 5 – Insert New Sector

Asks how many sectors to add (`qtdAdicionadoSetor`).

Increases `numSetores` by that amount and uses `realloc` to expand:

* `zoologico`
* `nomeSetores`

For each newly added sector:

* Allocates the cages and animal slots using `malloc`
* Allocates storage for the sector name

This allows the zoo to grow dynamically at runtime without restarting the program.

### Option 6 – Remove Sector

Asks for the name of the sector to remove and searches this sector in `nomeSetores`.

If found, the program:

* Frees all cages (`zoologico[setor][j]`)
* Frees the sector’s array (`zoologico[setor]`)
* Frees the sector name string (`nomeSetores[setor]`)

Then it shifts all subsequent sectors one position to the left to fill the gap.

Finally, it decrements `numSetores` and shrinks the arrays with `realloc`, printing a confirmation message.

If the sector is not found, it prints an error message.

### Option 7 – Tallest Animal in a Sector

Similar to the heaviest-animal option, but using the `altura` field:

* Asks for the sector name
* Searches for the sector
* Iterates over all cages and animals in that sector, tracking the greatest height

At the end, prints:

* Name of the tallest animal
* Its height in meters

If no animals are present, prints that there are no animals in the sector.

### Option 0 – Exit Program

When the user chooses `0`, the program:

* Iterates over all sectors and cages, freeing all dynamically allocated `info_animal` arrays
* Frees the arrays of sector pointers and sector names

Then it returns `0` and terminates cleanly.

---

## How to Compile and Run

### Requirements

* A C compiler (for example, `gcc`)
* A terminal (Linux, WSL, or similar)

### Compilation (Linux/WSL)

From the folder where `zoo_system.c` is located, run:

```bash
gcc -Wall -Wextra -std=c11 -o zoo_system zoo_system.c
```

This will generate an executable named `zoo_system`.

## Learning Outcomes

By building this project, the following skills were practiced:

- Defining and using `struct` types to model real-world entities (animals)
- Using multi-level pointers (`info_animal ***`) to simulate multi-dimensional dynamic arrays
- Applying dynamic memory allocation and `realloc` to grow and shrink structures at runtime
- Managing arrays of strings for sector names
- Implementing search operations over arrays (finding sectors and scanning animals)
- Implementing a menu-driven console application with `switch` and loops
- Properly freeing dynamically allocated memory at program termination

## Possible Improvements 

Judging from nowadays (Nov - 2025)
Future enhancements could include:

- Replacing `gets` with safer input functions (e.g., `fgets`) to avoid buffer overflows
- Validating user input more thoroughly:
  - Preventing negative or zero quantities for sectors, cages, or animals
  - Ensuring that names are not empty
- Allowing a variable number of animals per cage instead of a fixed `numAnimais`
- Adding new queries, such as:
  - Listing all animals in a given sector
  - Listing all animals in a specific cage
  - Searching animals by species or code
- Separating responsibilities into multiple source files:
  - `zoo_system.c` (main logic)
  - `zoo_memory.c` (allocation/deallocation)
  - `zoo_queries.c` (search and statistics)
- Adding persistence:
  - Saving and loading the zoo data from files
  - Exporting reports (e.g., all animals per sector)

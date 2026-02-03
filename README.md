# Snake Game (C)

A classic Snake game implemented in C for Linux terminals. This project features non-blocking input, high-score persistence, and a modular project structure.

## Project Structure

* src/: Implementation files.
    * main.c: Handles program flow and user input.
    * snake.c: Contains the core game logic and rendering.
* inc/: Header files.
    * snake.h: Function prototypes and definitions.
* Makefile: Build automation script.

## Getting Started

## Prerequisites

* A C compiler (GCC recommended)
* make build utility

## Building the Project

To compile the project and create the executable, run:

```bash
make

Running the Game
To start the application, run the generated executable:

Bash
./snake_game
Controls
W: Move Up

S: Move Down

A: Move Left

D: Move Right

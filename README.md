# Rock Paper Scissors Game

A classic Rock-Paper-Scissors game implementation in C++. Play against the computer for multiple rounds with score tracking and replay functionality.

## Features

- **Interactive Gameplay**: Play as many rounds as you want
- **Smart Computer Player**: Computer makes random moves to keep things unpredictable
- **Score Tracking**: Keeps track of wins, losses, and draws
- **Clean Interface**: Simple text-based UI with screen clearing between rounds
- **Input Validation**: Handles invalid inputs gracefully
- **Replay Option**: Play again without restarting the program

## How It Works

1. Player enters their choice (Rock, Paper, or Scissors)
2. Computer randomly generates its move
3. Winner is determined and displayed
4. Scores are updated
5. Player can choose to play again

## Technical Highlights

This project covers several important C++ concepts:

- **Random Number Generation**: Using rand() with srand(time(NULL))
- **Functions**: Modular code with clear responsibilities
- **Conditionals & Switch Statements**: Game logic and decision making
- **Loops**: For handling multiple rounds
- **String Manipulation**: Converting choices to readable output
- **User Input Handling**: Reading and validating player moves

## How to Compile & Run

```bash
g++ -o rps main.cpp
./rps
```

Or on Windows:

```bash
g++ -o rps.exe main.cpp
rps.exe
```

## Game Instructions

1. When prompted, enter your choice:
   - `1` for Rock
   - `2` for Paper
   - `3` for Scissors
2. The computer will make its move
3. Winner of the round is announced
4. Choose to play again or exit

## Game Rules

- Rock beats Scissors
- Scissors beats Paper
- Paper beats Rock
- Same choice = Draw

## Requirements

- C++ compiler (g++, clang, or MSVC)
- No external libraries needed

---

Feel free to fork, modify, or use this as a learning resource!

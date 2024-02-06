# Hangman Game

This is a command-line Hangman game implemented in C.

## Description

Hangman is a classic word-guessing game where players try to guess a hidden word by suggesting letters within a limited number of attempts. This implementation includes multiple difficulty levels and customizable word categories.

## Features

- Three difficulty levels: easy, normal, and hard.
- Customizable word categories with corresponding hints.
- ASCII art hangman display.
- Help message for incorrect guesses.
- Option to return to the main menu or exit the game after each round.

## How to Play

1. Run the executable file or compile and execute the source code.
2. Choose from the main menu:
   - Play the game.
   - View game creator information.
   - Read game instructions.
   - Exit the game.
3. If playing the game:
   - Select a difficulty level: easy, normal, or hard.
   - Guess letters to reveal the hidden word.
   - Use the hint to guess the word correctly.
   - Avoid exceeding the maximum allowed mistakes based on the chosen difficulty level.
4. After each round, decide whether to return to the main menu or exit the game.

## Files

- `hangman.c`: Contains the source code for the Hangman game.
- `README.md`: This readme file providing information about the game.

## Compilation and Execution

Compile the `hangman.c` source file using a C compiler such as GCC:

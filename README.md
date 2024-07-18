# Tic Tac Toe Console Game

## Overview

This is a simple Tic Tac Toe game implemented in C++. The game allows two players to play Tic Tac Toe in the console. The game board is displayed in the console, and players take turns to input their moves.

## Features

- Two-player mode
- Simple and intuitive console interface
- Input validation to ensure valid moves
- Game state display after each move

## How to Play

1. Clone this repository to your local machine.
2. Navigate to the project directory.
3. Compile the program using a C++ compiler.
4. Run the compiled executable to start the game.
5. Follow the on-screen instructions to play the game.

## Setup and Compilation

### Prerequisites

- Download and Install cmake
- Need visual studio developer tools for windows 
- A C++ compiler (e.g., g++, clang++) on Linux
- A terminal or command prompt

## Compilation

### Windows

1. Open your visual studio developer command prompt
2. Navigate to the directory containing the source code.
3. Compile the program using .\build.bat -b Release
4. Run the compiled executable:

    ```bat
    .\build\Release\tic_tac_toe.exe
    ```
	
### Unix

1. Open your terminal
2. Navigate to the directory containing the source code.
3. Compile the program using ./build.sh -b Release
4. Run the compiled executable:

    ```sh
    ./build/tic_tac_toe
    ```
	
## Usage

Once you run the executable, the game will prompt you to enter moves for User_01 (X) and User_02 (O). The game board is a 3x3 grid with positions numbered from 1 to 9 as follows:

```
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
```

Players will enter the number corresponding to the position where they want to place their mark (X or O). The game will check for a win condition or a draw after each move and display the result accordingly.

## Example Gameplay

User_01 (X) - Enter position: 1

```
| X |   |   |
|   |   |   |
|   |   |   |
```

User_02 (O) - Enter position: 5

```
| X |   |   |
|   | O |   |
|   |   |   |
```

User_01 (X) - Enter position: 2

```
| X | X |   |
|   | O |   |
|   |   |   |
```

... and so on, until the game ends with a win or a draw.

## Contributing

Contributions are welcome! If you have any improvements or bug fixes, feel free to open a pull request. Please ensure that your code follows the existing style and structure of the project.

## License

This project is licensed under the GNU General Public License (GPL). See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by the classic Tic Tac Toe game.

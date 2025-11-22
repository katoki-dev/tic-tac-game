# Tic-Tac-Toe in C  

## 📌 Overview  
This is an enhanced **Tic-Tac-Toe** game implemented in C with improved visuals and user experience. It allows two players to play in the terminal with a beautiful colored interface, robust input validation, and ergonomic gameplay features.  

## 🎯 Features  
✅ Two-player mode (Player 1: 'X', Player 2: 'O')  
✅ **Beautiful colored interface** with ANSI colors (Cyan X, Magenta O)  
✅ **Enhanced board design** using Unicode box-drawing characters  
✅ **Robust input validation** (invalid positions, occupied cells, non-numeric input)  
✅ **Clear screen between moves** for better visibility  
✅ **Play again option** - no need to restart the program  
✅ Checks for horizontal, vertical, and diagonal wins  
✅ Detects a draw if the board is full  
✅ **User-friendly prompts and error messages** with emoji indicators  

## 📂 File Structure  
- **tttgame.c** → Main program file containing the game logic  

## 🛠 Installation & Usage  
### 1️⃣ Clone the Repository  
```sh  
git clone https://github.com/katoki-dev/tic-tac-game.git  
cd tic-tac-game  
```  
### 2️⃣ Compile the program  
```sh  
gcc tttgame.c -o tic_tac_toe  
```  
### 3️⃣ Run the game  
```sh  
./tic_tac_toe  
```  
### 4️⃣ How to Play  
- Players take turns entering a number (1-9) to place their mark on the board.  
- **Position 1** is top-left, **Position 9** is bottom-right.
- The game validates your input and shows clear error messages for invalid moves.
- After each game, you can choose to play again or exit.

## 🎨 Visual Improvements
- **Colorful interface**: X appears in cyan, O appears in magenta, available positions in yellow
- **Box-drawing characters**: Professional-looking grid with Unicode borders
- **Clear screen**: Fresh view after each move for better focus
- **Emoji indicators**: Visual feedback for game states (🎮 game, 🏁 game over, 🎉 winner, ❌ errors)

## 🔧 Ergonomic Improvements
- **Input validation**: Prevents invalid moves (out of range, occupied cells, non-numeric input)
- **Error messages**: Clear feedback when something goes wrong
- **Play again**: Continue playing without restarting the program
- **Fixed position bug**: Corrected indexing for positions 1-9

## 🏆 Winning Conditions  
The game checks for a win based on:  
- **Horizontal Line** ✅  
- **Vertical Line** ✅  
- **Diagonal Line** ✅ 

💡 Feel free to contribute or modify the code! Let me know if you have any suggestions. 🚀


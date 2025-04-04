# Tic-Tac-Toe in C  

## 📌 Overview  
This is a simple **Tic-Tac-Toe** game implemented in C. It allows two players to play in the terminal, taking turns to place 'X' and 'O' on a 3×3 board. The game checks for a winner after each move and announces the result.  

## 🎯 Features  
✅ Two-player mode (Player 1: 'X', Player 2: 'O')  
✅ Simple command-line interface  
✅ Checks for horizontal, vertical, and diagonal wins  
✅ Detects a draw if the board is full  

## 📂 File Structure  
- **tic.c** → Main program file containing the game logic  

## 🛠 Installation & Usage  
### 1️⃣ Compile the program  
```sh  
gcc tttgame.c -o tic_tac_toe  
```  
### 2️⃣ Run the game  
```sh  
./tic_tac_toe  
```  
### 3️⃣ How to Play  
- Players take turns entering a number (1-9) to place their mark on the board.  
- The game announces the winner or a draw when all moves are played.  

## 🏆 Winning Conditions  
The game checks for a win based on:  
- **Horizontal Line** ✅  
- **Vertical Line** ✅  
- **Diagonal Line** ✅  

💡 Feel free to contribute or modify the code! Let me know if you have any suggestions. 🚀 

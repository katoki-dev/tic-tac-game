#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ANSI color codes for better visuals
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_WHITE   "\033[1;37m"

char board[3][3];
int turn;

// Clear screen function for better visual experience
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void reset(){
    char l='1';
    int i,j;
    turn=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            board[i][j]=l;
            l=l+1;
        }
    }
}

// Display the game board with better visuals
void show()
{
    int i,j;
    printf("\n");
    printf("     ╔═══════╦═══════╦═══════╗\n");
    for(i=0;i<3;i++){
        printf("     ║");
        for(j=0;j<3;j++){
            printf("   ");
            // Color code X and O for better distinction
            if(board[i][j] == 'X') {
                printf("%s%c%s", COLOR_CYAN, board[i][j], COLOR_RESET);
            } else if(board[i][j] == 'O') {
                printf("%s%c%s", COLOR_MAGENTA, board[i][j], COLOR_RESET);
            } else {
                printf("%s%c%s", COLOR_YELLOW, board[i][j], COLOR_RESET);
            }
            printf("   ║");
        }
        printf("\n");
        if(i!=2)
            printf("     ╠═══════╬═══════╬═══════╣\n");
    }
    printf("     ╚═══════╩═══════╩═══════╝\n");
    printf("\n");
}

// Make a move with proper validation and error handling
int makeMove(int position, int player){
    // Convert 1-9 position to array indices (fixing the original bug)
    if(position < 1 || position > 9) {
        printf("%s     ❌ Invalid position! Please enter a number between 1-9.%s\n\n", COLOR_RED, COLOR_RESET);
        return player == 1 ? 1 : 2; // Return current player to retry
    }
    
    int i = (position - 1) / 3;  // Fixed: subtract 1 first
    int j = (position - 1) % 3;  // Fixed: subtract 1 first
    
    if(board[i][j] == 'X' || board[i][j] == 'O') {
        printf("%s     ❌ Cell already occupied! Choose another position.%s\n\n", COLOR_RED, COLOR_RESET);
        return player == 1 ? 1 : 2; // Return current player to retry
    }
    
    if(player == 1){
        board[i][j] = 'X';
    } else {
        board[i][j] = 'O';
    }
    turn++;
    return player == 1 ? 2 : 1; // Switch player
}

int verticalcheck(){
    int i;
    for(i=0;i<3;i++){
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
            return 1;
    }
    return 0;
}

int horizontalcheck(){
    int i;
    for(i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
            return 1;
    }
    return 0;
}

int diagonalcheck(){
    if((board[0][0]==board[1][1]&&board[1][1]==board[2][2])||(board[0][2]==board[1][1]&&board[1][1]==board[2][0]))
        return 1;
    return 0;
}

int check(){
    if(verticalcheck()||horizontalcheck()||diagonalcheck())
        return 1;
    else
        return 0;
}

int main()
{
    char playAgain;
    
    do {
        int choice, player = 1;
        reset();
        clearScreen();
        
        // Display welcome message with better formatting
        printf("\n");
        printf("%s╔════════════════════════════════════════╗%s\n", COLOR_GREEN, COLOR_RESET);
        printf("%s║                                        ║%s\n", COLOR_GREEN, COLOR_RESET);
        printf("%s║        🎮 TIC-TAC-TOE GAME 🎮         ║%s\n", COLOR_GREEN, COLOR_RESET);
        printf("%s║                                        ║%s\n", COLOR_GREEN, COLOR_RESET);
        printf("%s╚════════════════════════════════════════╝%s\n", COLOR_GREEN, COLOR_RESET);
        printf("\n");
        printf("     Player 1: %sX%s  |  Player 2: %sO%s\n", COLOR_CYAN, COLOR_RESET, COLOR_MAGENTA, COLOR_RESET);
        printf("\n");
        
        while(turn < 9){
            show();
            
            if(check())
                break;
            
            // Display current player with better formatting
            if(player == 1)
                printf("     %s▶ Player 1 [%sX%s] - Your turn!%s\n", COLOR_WHITE, COLOR_CYAN, COLOR_WHITE, COLOR_RESET);
            else
                printf("     %s▶ Player 2 [%sO%s] - Your turn!%s\n", COLOR_WHITE, COLOR_MAGENTA, COLOR_WHITE, COLOR_RESET);
            
            printf("     Enter position (1-9): ");
            
            if(scanf("%d", &choice) != 1) {
                // Clear invalid input
                while(getchar() != '\n');
                printf("%s     ❌ Invalid input! Please enter a number.%s\n\n", COLOR_RED, COLOR_RESET);
                continue;
            }
            
            int previousPlayer = player;
            player = makeMove(choice, player);
            
            // Only clear screen if move was successful
            if(player != previousPlayer) {
                clearScreen();
                printf("\n");
                printf("%s╔════════════════════════════════════════╗%s\n", COLOR_GREEN, COLOR_RESET);
                printf("%s║        🎮 TIC-TAC-TOE GAME 🎮         ║%s\n", COLOR_GREEN, COLOR_RESET);
                printf("%s╚════════════════════════════════════════╝%s\n", COLOR_GREEN, COLOR_RESET);
                printf("\n");
                printf("     Player 1: %sX%s  |  Player 2: %sO%s\n", COLOR_CYAN, COLOR_RESET, COLOR_MAGENTA, COLOR_RESET);
                printf("\n");
            }
        }
        
        show();
        
        // Display game result with better formatting
        printf("\n");
        printf("%s     ═══════════════════════════════════%s\n", COLOR_YELLOW, COLOR_RESET);
        printf("%s              🏁 GAME OVER 🏁%s\n", COLOR_YELLOW, COLOR_RESET);
        printf("%s     ═══════════════════════════════════%s\n", COLOR_YELLOW, COLOR_RESET);
        printf("\n");
        
        if(check()){
            if(player == 2)
                printf("%s     🎉 Player 1 [%sX%s] WINS! 🎉%s\n", COLOR_GREEN, COLOR_CYAN, COLOR_GREEN, COLOR_RESET);
            else
                printf("%s     🎉 Player 2 [%sO%s] WINS! 🎉%s\n", COLOR_GREEN, COLOR_MAGENTA, COLOR_GREEN, COLOR_RESET);
        } else {
            printf("%s     🤝 It's a DRAW! 🤝%s\n", COLOR_YELLOW, COLOR_RESET);
        }
        
        printf("\n");
        printf("     Play again? (y/n): ");
        scanf(" %c", &playAgain);
        
    } while(playAgain == 'y' || playAgain == 'Y');
    
    printf("\n");
    printf("%s     Thanks for playing! Goodbye! 👋%s\n\n", COLOR_GREEN, COLOR_RESET);
    
    return 0;
}

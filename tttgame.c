#include<stdio.h>
#include<stdlib.h>

char board[3][3];
int turn;

int reset(){
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

int show()
{
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("\t%c",board[i][j]);
            if(j!=2)
                printf("\t|");
        }
        printf("\n");
        if(i!=2)
        printf("--------------------------------------------------\n");
    }
}

int move(int move,int player){
int i=move/3;
int j=(move%3)-1;
if(board[i][j]!='X' && board[i][j]!='O')
{
if(player==1){
board[i][j]='X';
player=2;
}
else{
board[i][j]='O';
player=1;
}
turn=turn+1;
}
return player;
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
    int choice,i,j,player=1;
    reset();
    printf("\t Player 1  =  X\n\t Player 2  =  O\n\n");
    while(turn<9){
        show();
        if(check())
            break;
        if(turn%2==0)
            printf("\tPlayer 1 [ X ]\n");
        else
            printf("\tPlayer 2 [ O ]\n");
        printf("\tEnter your move :");
        scanf("%d",&choice);
        player=move(choice,player);
    }
    show();
    printf("\n\t----- Game Over -----\n\n");
    if(check()){
        if(turn%2!=0)
            printf("\t----- Player 1 [ X ] Wins -----\n");
        else
            printf("\t----- Player 2 [ O ] Wins -----\n");
    }
    else
    printf("\t----- DRAW -----\n");
 }

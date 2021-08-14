//Compile and run in TurboC
//change N to resize board on compile
#define N 21
#include <stdio.h>
#include <conio.h>

void printSolution(int board[N][N]){
    for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++){
		if(board[i][j]==1)
			textcolor(BLINK+YELLOW);
		else textcolor(WHITE);
	    cprintf("%d ", board[i][j]);
    }
		printf("\n");
    }
    gotoxy(80,1);
}

int isSafe(int board[N][N], int row, int col){
    int i, j;
    /* Check this row on left side */
    for (i = 0; i < col; i++)
	if (board[row][i])
	    return 0;
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	if (board[i][j])
	    return 0;
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
	if (board[i][j])
	    return 0;
    return 1;
}

/* A recursive utility function to solve N
   Queen problem */
int solveNQUtil(int board[N][N], int col){
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
	return 1;
    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < N; i++){
	/* Check if the queen can be placed on
	  board[i][col] */
	if (isSafe(board, i, col)==1){
	    /* Place this queen in board[i][col] */
	    board[i][col] = 1;

	    /* recur to place rest of the queens */
	    if (solveNQUtil(board, col + 1))
		return 1;
	    /* If placing queen in board[i][col]
	       doesn't lead to a solution,
	       remove queen from board[i][col] */
	    board[i][col] = 0; // BACKTRACK
	}
    }
    /* If queen cannot be placed in any row in
	this colum col, return false */
    return 0;
}

void solveNQ(){
    int board[N][N] = {0};
    if (solveNQUtil(board, 0) == 0){
	textcolor(WHITE);
	printf("Solution does not exist");

    }
    printSolution(board);
}

void main(){
    solveNQ();
    getch();
    clrscr();
}

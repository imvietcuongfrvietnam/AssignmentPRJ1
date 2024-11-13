#include<stdio.h>

int soduku[9][9];
int k = 0;

void ghinhan(){
    k++;
}

void Try(int h, int c){
    if(h == 9){ // If we've reached the 9th row, a solution has been found
        ghinhan();
        return;
    }
    
    // Move to the next row if we've reached the last column
    if(c == 9){
        Try(h + 1, 0);
        return;
    }

    // If this cell is already filled, move to the next column
    if(soduku[h][c] != 0){
        Try(h, c + 1);
        return;
    }
    
    // Try numbers 1 to 9 in the current empty cell
    for(int i = 1; i <= 9; i++){
        // Check if the number i is already in the current row
        int valid = 1;
        for(int j = 0; j < 9; j++){
            if(soduku[h][j] == i || soduku[j][c] == i){ // Check row and column
                valid = 0;
                break;
            }
        }

        // Check if the number i is in the current 3x3 subgrid
        int H = h / 3, C = c / 3;
        for(int m = 3*H; m < 3*H + 3; m++){
            for(int n = 3*C; n < 3*C + 3; n++){
                if(soduku[m][n] == i){
                    valid = 0;
                    break;
                }
            }
        }

        if(valid){
            soduku[h][c] = i;  // Place the number in the cell
            Try(h, c + 1);     // Move to the next cell
            soduku[h][c] = 0;  // Backtrack (reset the cell)
        }
    }
}

int main(){
    // Input the Sudoku puzzle
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &soduku[i][j]);
        }
    }
    
    // Start solving from the first cell (0,0)
    Try(0, 0);

    // Output the number of solutions found
    printf("%d", k);
}


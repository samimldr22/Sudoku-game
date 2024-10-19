#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                printf(" | ");
            printf("%d ", grid[row][col]);
        }
        if (row == 2 || row == 5) {
            printf("\n");
            for (int i = 0; i < N; i++)
                printf("---");
        }
        printf("\n");
    }
}

// Function to check if placing a number is valid
bool isValid(int grid[N][N], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num)
            return false;
    }

    // Check the column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num)
            return false;
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

// Function to check if the grid is fully filled
bool isGridFull(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0)
                return false;
        }
    }
    return true;
}

// Function to allow the user to play the game
void playSudoku(int grid[N][N]) {
    int row, col, num;
    while (!isGridFull(grid)) {
        printGrid(grid);
        printf("Enter row (0-8), column (0-8), and number (1-9) to fill (separated by space): ");
        scanf("%d %d %d", &row, &col, &num);

        if (row < 0 || row >= N || col < 0 || col >= N || num < 1 || num > 9) {
            printf("Invalid input! Please enter numbers within range.\n");
            continue;
        }

        if (grid[row][col] != 0) {
            printf("Cell already filled! Choose another cell.\n");
        } else if (!isValid(grid, row, col, num)) {
            printf("Invalid move! Number can't be placed here.\n");
        } else {
            grid[row][col] = num;
        }
    }
    printf("Congratulations! You completed the Sudoku.\n");
}

// Main function to initialize the game
int main() {
    // 0 represents empty spaces in the Sudoku grid
    int grid[N][N] = {
    {0, 8, 4, 5, 3, 2, 1, 7, 0}, 
    {0, 5, 6, 0, 1, 0, 0, 0, 0}, 
    {0, 0, 1, 6, 8, 7, 4, 0, 9}, 
    {0, 0, 8, 1, 0, 0, 6, 2, 7}, 
    {0, 4, 0, 0, 9, 0, 0, 0, 1}, 
    {0, 6, 3, 2, 7, 5, 0, 0, 4}, 
    {0, 1, 2, 0, 0, 0, 0, 4, 0}, 
    {6, 0, 9, 4, 0, 8, 7, 0, 0}, 
    {4, 7, 5, 0, 2, 0, 9, 0, 8} 
};


    printf("Welcome to the Sudoku Game!\n");
    playSudoku(grid);

    return 0;
} 

#include <stdio.h>
#include <stdlib.h>

int directions[4][2] = {
    {-1, 0}, // Up
    {1, 0},  // Down
    {0, -1}, // Left
    {0, 1}   // Right
};

int DFS(int matrix[][3], int i, int j, int** memo, int rows, int cols) {
    if (memo[i][j] > 0) return memo[i][j];
    
    int maxLength = 1;
    size_t m, n, newRow, newCol;

    for (m = 0; m < 4; m++)
    {
        newRow = i + directions[m][0];
        newCol = j + directions[m][1];

        if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && matrix[i][j] < matrix[newRow][newCol]) {
            int length = 1 + DFS(matrix, newRow, newCol, memo, rows, cols);
            if (maxLength < length) maxLength = length;
        }
    }

    memo[i][j] = maxLength;
    
    return maxLength;
}

int LongestIncreasingPath(int matrix[][3], int rows, int cols) {
    int maxLength = 1;
    int** memo;
    size_t i, j;

    memo = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        memo[i] = (int*)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++)
        {
            memo[i][j] = 0;
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            int length = DFS(matrix, i, j, memo, rows, cols);
            if (length > maxLength) maxLength = length;
        }
    }

    for (i = 0; i < rows; i++) {
        free(memo[i]);
    }
    free(memo);

    return maxLength;
}

int main() {
    int matrix[3][3] = {
        {9, 2, 1},
        {0, 3, 4},
        {7, 6, 5}
    };

    int result = LongestIncreasingPath(matrix, 3, 3);
    printf("Longest increasing path length: %d\n", result);

    return 0;
}
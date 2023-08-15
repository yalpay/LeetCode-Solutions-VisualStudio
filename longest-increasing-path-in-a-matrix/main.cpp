#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> directions = {
    {-1, 0}, // Up
    {1, 0},  // Down
    {0, -1}, // Left
    {0, 1}   // Right
};

int DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
    if (memo[i][j] != 0) return memo[i][j]; // Return if already calculated

    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxLength = 1; // Minimum length is 1 (the cell itself)

    for (const auto& dir : directions) {
        int newRow = i + dir[0];
        int newCol = j + dir[1];

        // Check if new position is within bounds and has increasing value
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[i][j]) {
            int length = 1 + DFS(matrix, newRow, newCol, memo);
            maxLength = max(maxLength, length);
        }
    }

    memo[i][j] = maxLength; // Store calculated value in memo table
    return maxLength;
}

int LongestIncreasingPath(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;

    int cols = matrix[0].size();
    vector<vector<int>> memo(rows, vector<int>(cols, 0)); // Memoization table

    int maxLength = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int length = DFS(matrix, i, j, memo);
            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

int main() {
    vector<vector<int>> matrix = {
        {9, 2, 1},
        {0, 3, 4},
        {7, 6, 5}
    };

    int result = LongestIncreasingPath(matrix);
    cout << "Longest increasing path length: " << result << endl;

    return 0;
}

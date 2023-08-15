using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace longest_increasing_path_in_a_matrix_C_
{
    // https://leetcode.com/problems/longest-increasing-path-in-a-matrix
    public class Solution
    {
        public int LongestIncreasingPath(int[][] matrix)
        {
            int rows = matrix.Length;
            if (rows == 0) return 0;

            int cols = matrix[0].Length;
            int[,] memo = new int[rows, cols]; // Memoization table

            int maxLength = 0;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    int length = DFS(matrix, i, j, memo);
                    maxLength = Math.Max(maxLength, length);
                }
            }

            return maxLength;
        }

        public static int[][] directions = {
            new int[] { -1, 0 }, // Up
            new int[] { 1, 0 },  // Down
            new int[] { 0, -1 }, // Left
            new int[] { 0, 1 }   // Right
        };

        public int DFS(int[][] matrix, int i, int j, int[,] memo)
        {
            if (memo[i, j] != 0) return memo[i, j]; // Return if already calculated

            int rows = matrix.Length;
            int cols = matrix[0].Length;
            int maxLength = 1; // Minimum length is 1 (the cell itself)

            foreach (var dir in directions)
            {
                int newRow = i + dir[0];
                int newCol = j + dir[1];

                // Check if new position is within bounds and has increasing value
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[i][j])
                {
                    int length = 1 + DFS(matrix, newRow, newCol, memo);
                    maxLength = Math.Max(maxLength, length);
                }
            }

            memo[i, j] = maxLength;
            return maxLength;
        }
    }
}


namespace longest_increasing_path_in_a_matrix_C_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[][] matrix = new int[][] {
                new int[] { 9, 2, 1 },
                new int[] { 0, 3, 4 },
                new int[] { 7, 6, 5 }
            };

            Solution solution = new Solution();
            int result = solution.LongestIncreasingPath(matrix);

            Console.WriteLine(result);
        }
    }
}
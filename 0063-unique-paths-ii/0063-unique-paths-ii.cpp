class Solution {
public:

    int helper(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if(row == 0 && col == 0 && grid[row][col] == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(grid[row][col] == 1) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int left = helper(row - 1, col, dp, grid);
        int right = helper(row, col - 1, dp, grid);

        return dp[row][col] = left + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>> grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m - 1, n - 1, dp, grid);
    }
};
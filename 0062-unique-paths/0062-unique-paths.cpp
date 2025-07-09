class Solution {
public:

    int helper(int row, int col, vector<vector<int>>& dp) {
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int left = helper(row - 1, col, dp);
        int right = helper(row, col - 1, dp);

        return dp[row][col] = left + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m - 1, n - 1, dp);
    }
};
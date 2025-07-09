class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));

        //base case
        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i < m && j < n) {
                    int left = 0, right = 0;
                    if(i == 0 && j == 0) continue;
                    if(i > 0) left = dp[i - 1][j];
                    if(j > 0) right = dp[i][j - 1];

                    dp[i][j] = left + right;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// class Solution {
// public:
//     int helper(int row, int col, vector<vector<int>>& dp) {
//         if(row == 0 && col == 0) return 1;
//         if(row < 0 || col < 0) return 0;

//         if(dp[row][col] != -1) return dp[row][col];

//         int left = helper(row - 1, col, dp);
//         int right = helper(row, col - 1, dp);

//         return dp[row][col] = left + right;
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         return helper(m - 1, n - 1, dp);
//     }
// };
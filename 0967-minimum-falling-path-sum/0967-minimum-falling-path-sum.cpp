class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n =  matrix.size();

        vector<vector<int>> dp(n, vector<int> (n, -1));

        for(int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {
                int two = INT_MAX, three = INT_MAX;
                int one = dp[row - 1][col];
                if(col < n - 1) two = dp[row - 1][col + 1];
                if(col > 0) three = dp[row - 1][col - 1];

                dp[row][col] = matrix[row][col] + min(one, min(two, three));
            }
        }
        int ans = 1e9;
        for(auto it: dp[n - 1]) {
            ans = min(ans, it);
        }
        return ans;
    }
};



// class Solution {
// public:
//     int helper(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp) {
//         if(row == 0) return matrix[0][col];

//         if(dp[row][col] != -1) return dp[row][col];

//         int two = INT_MAX, three = INT_MAX;
//         int one = helper(row - 1, col, matrix, n, dp);
//         if(col < n - 1) two = helper(row - 1, col + 1, matrix, n, dp);
//         if(col > 0) three = helper(row - 1, col - 1, matrix, n, dp);

//         return dp[row][col] = matrix[row][col] + min(one, min(two, three));
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int ans = INT_MAX;

//         vector<vector<int>> dp(m, vector<int> (m, -1));
//         for(int i = 0; i < m; i++) {
//             ans = min(ans, helper(m - 1, i, matrix, m, dp));
//         }
//         return ans;
//     }
// };
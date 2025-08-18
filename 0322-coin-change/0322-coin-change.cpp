// class Solution {
// public:
//     int helper(int index, vector<int>& coins, int amount,vector<vector<int>>& dp) {
//         if(index == 0) {
//             if(amount % coins[0] == 0) return amount / coins[0];
//             return 1e9;
//         } 
//         if(dp[index][amount] != -1) return dp[index][amount];
//         int pick = 1e9;
//         if(coins[index] <= amount) pick = 1 + helper(index, coins, amount - coins[index], dp);
//         int notPick = helper(index - 1, coins, amount, dp);
//         return dp[index][amount] = min(pick, notPick);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         if(amount == 0) return 0;
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//         sort(coins.begin(), coins.end());
//         int ans = helper(n - 1, coins, amount, dp);
//         return ans == 1e9 ? -1 : ans;
//     }
// };  
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        sort(coins.begin(), coins.end());

        for(int a = 0; a <= amount; a++) {
            if(a % coins[0] == 0) dp[0][a] = a / coins[0];
        }

        for(int i = 1; i < n; i++) {
            for(int a = 0; a <= amount; a++) {
                int pick = 1e9;
                if(coins[i] <= a) pick = 1 + dp[i][a - coins[i]];
                int notPick = dp[i - 1][a];

                dp[i][a] = min(pick, notPick);
            }
        }

        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
};
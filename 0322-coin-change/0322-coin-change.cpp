class Solution {
public:
    int helper(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // base case
        if(index < 0) return 1e9;
        if(amount == 0) return 0;

        if(dp[index][amount] != -1) return dp[index][amount];
        
        int pick = 1e9;
        if(coins[index] <= amount) pick = 1 + helper(index, coins, amount - coins[index], dp);
        int notPick = helper(index - 1, coins, amount, dp);

        return dp[index][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        if(amount == 0) return 0;
        sort(coins.begin(), coins.end());
        

        int ans = helper(n - 1, coins, amount, dp);

        return ans == 1e9 ? -1 : ans;
    }
};
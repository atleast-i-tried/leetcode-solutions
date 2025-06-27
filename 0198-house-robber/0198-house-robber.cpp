class Solution {
public:
    int robbing(vector<int>& nums, int i, vector<int>& dp) {
        if(i == 0) return nums[i];
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + robbing(nums, i - 2, dp);
        int notPick = 0 + robbing(nums, i - 1, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp(n, -1);
        int ans  = robbing(nums, n - 1, dp);
        return ans;
    }
};
class Solution {
public:
    int robbing(vector<int>& nums, int start, int end, vector<int> &dp) {
        if(end == start) return nums[start];
        if(end < start) return 0;
        if(dp[end] != -1) return dp[end];

        int pick = nums[end] + robbing(nums, start, end - 2, dp);
        int notPick = robbing(nums, start, end - 1, dp);

        return dp[end] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int ans1  = robbing(nums, 0, n - 2, dp1);
        int ans2  = robbing(nums, 1, n - 1, dp2);
        return max(ans1, ans2);
    }
};
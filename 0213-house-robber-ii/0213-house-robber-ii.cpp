class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];

        if (n > 2) dp2[2] = max(nums[1], nums[2]);

        for (int i = 2; i <= n - 2; i++) {
            int pick = nums[i] + dp1[i - 2];
            int notPick = dp1[i - 1];
            dp1[i] = max(pick, notPick);
        }

        for (int i = 3; i <= n - 1; i++) {
            int pick = nums[i] + dp2[i - 2];
            int notPick = dp2[i - 1];
            dp2[i] = max(pick, notPick);
        }

        return max(dp2[n - 1], dp1[n - 2]);
    }
};

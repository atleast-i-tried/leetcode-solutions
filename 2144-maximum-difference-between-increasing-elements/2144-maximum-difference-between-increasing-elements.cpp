class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == mini) continue;
            ans = max(nums[i] - mini, ans);
            mini = min(mini, nums[i]);
        }
        return ans;
    }
};
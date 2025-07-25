class Solution {
public:
    int helper(int index, vector<int>& nums, int target) {
        if(index == 0) {
            return (nums[0] == target) + (nums[0] == -target);
        }

        int left = helper(index - 1, nums, target + nums[index]);
        int right = helper(index - 1, nums, target - nums[index]);

        return left + right;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return helper(n - 1, nums, target);
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        int maxSum = 0;

        for(int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            sum += nums[right];

            while(mp[nums[right]] > 1) {
                mp[nums[left]]--;
                sum -= nums[left];
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }

            

            maxSum = max(sum, maxSum);

        }
        return maxSum;
    }
};
class Solution {
private:
    int helper(vector<int>& nums, int k) {
        int right = 0;
        int left = 0;
        int subarrayCnt = 0;
        unordered_map<int, int> mp;

        for(right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while(mp.size() > k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }

            subarrayCnt += right - left + 1;
        }
        return subarrayCnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
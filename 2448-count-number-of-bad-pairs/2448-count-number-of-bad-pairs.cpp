class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n  = nums.size();
        long long goodPairs = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            goodPairs += mp[nums[i] - i];
            mp[nums[i] - i]++;
        }

        return 1LL * (n * (n - 1) / 2) - goodPairs;
    }
};
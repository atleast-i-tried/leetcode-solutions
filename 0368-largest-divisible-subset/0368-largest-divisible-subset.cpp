class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        vector<int> result;

        for (int num : nums) {
            vector<int> maxSubset;

            for (auto& [key, subset] : mp) {
                if (num % key == 0 && subset.size() > maxSubset.size()) {
                    maxSubset = subset;
                }
            }

            maxSubset.push_back(num);
            mp[num] = maxSubset;

            if (maxSubset.size() > result.size()) {
                result = maxSubset;
            }
        }

        return result;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> renums(nums.begin(), nums.end());
        renums.insert(renums.end(), nums.begin(), nums.end());  
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total < x) return -1;

        int left = 0, sum = 0, ans = INT_MAX;

        for (int right = 0; right < renums.size(); ++right) {
            sum += renums[right];
            while (sum >= x) {
                if ((left == nums.size() || right == nums.size() - 1 || 
                    (left < nums.size() && right >= nums.size())) && sum == x) {
                    ans = min(ans, right - left + 1);
                }
                sum -= renums[left++];
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

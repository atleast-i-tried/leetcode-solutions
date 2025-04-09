class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // if(nums.size() == 1 && nums[0] < k) return -1;
        unordered_map<int, int> mp;
        int cnt = 0;

        for(int i: nums) {
            mp[i] = 1;
        }

        for(auto [key, value]: mp) {
            if(key > k) cnt++;
        }

        if(cnt == mp.size()) return cnt;

        if(cnt == mp.size() - 1 && mp.find(k) != mp.end()) return cnt;
        return -1;
    }
};
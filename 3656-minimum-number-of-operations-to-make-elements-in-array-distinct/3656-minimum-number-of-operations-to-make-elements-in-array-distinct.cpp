class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int curIdx = 0;
        int cnt = 0;

        for(int i = nums.size() - 1; i >= 0; i--) {
            mp[nums[i]]++;
            curIdx = i;
            if(mp[nums[i]] > 1) break;
        }

        for(auto [key, value]: mp) {
            if(value == 1) cnt++;
        }

        if(cnt == nums.size()) return 0;

        return (curIdx / 3) + 1;
    }
};
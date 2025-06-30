class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;

        for (auto it : nums) mp[it]++;

        int temp = INT_MAX;
        int cnt = 0;
        bool first = true;

        for (auto [key, value] : mp) {
            if (!first && abs(key - temp) == 1) {
                cnt = max(cnt, mp[key] + mp[temp]);
            }
            temp = key;
            first = false;
        }

        return cnt;
    }
};

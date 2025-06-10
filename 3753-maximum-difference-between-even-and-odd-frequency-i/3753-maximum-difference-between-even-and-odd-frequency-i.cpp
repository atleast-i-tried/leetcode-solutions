class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for(auto it: s) mp[it]++;

        int odd = 0, even = INT_MAX;

        for(auto [key, value]: mp) {
            if(value % 2) {
                odd = max(value, odd);
            } else {
                even = min(value, even);
            }
        }

        return odd - even;
    }
};
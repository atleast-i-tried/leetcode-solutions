class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;

        for(auto it: nums) {
            maxi = max(maxi, ++mp[it]);
        }
        
        int cnt = 0;

        for(auto it: mp) {
            if(maxi == it.second) {
                cnt++;
            }
        }
        return cnt * maxi;
    }
};
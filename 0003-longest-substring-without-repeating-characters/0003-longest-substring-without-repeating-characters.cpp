class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int cnt = 0;
        unordered_map<char, int> mp;
        int n = s.size();

        for(right = 0; right < n; right++) {

            while(mp.find(s[right]) != mp.end()) {
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }

            cnt = max(cnt, right - left + 1);

            mp[s[right]]++;
        }
        return cnt;
    }
};
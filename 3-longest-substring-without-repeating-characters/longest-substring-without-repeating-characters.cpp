class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0, len = 0;

        for(int right = 0; right < s.size(); right++) {
            mp[s[right]]++;

            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }

            len = max(len, right - left + 1);
        }
        return len;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        int left = 0;
        int right = 0;
        int cnt = 0;
        int length = INT_MAX;
        int index = -1;
        unordered_map<char, int> mp;

        for(char c: t) {
            mp[c]++;
        }

        for(right = 0; right < s.size(); right++) {
            
            if(mp[s[right]] > 0) {
                cnt++;
            }
            mp[s[right]]--;

            while(cnt == t.size()) {
                if(length > right - left + 1) {
                    length = right - left + 1;
                    index = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) {
                    cnt--;
                }
                left++;
            }
        }
        return index == -1 ? "" : s.substr(index, length);
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int right = 0;
        int left = 0;
        int cnt = 0;
        unordered_map<char, int> mp;

        for(right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while(mp.size() == 3) {
                cnt += s.size() - right;
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            
        }
        return cnt;
    }
};
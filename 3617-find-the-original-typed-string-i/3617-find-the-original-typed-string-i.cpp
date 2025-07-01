class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char, int> mp;
        char temp = word[0];
        int cnt = 1;

        for(int i = 1; i < word.size(); i++) {
            if(word[i] == temp) {
                cnt++;
            } else {
                if(mp.find(temp) != mp.end()) {
                    mp[temp] += cnt - 1;
                } else mp[temp] = cnt;
                cnt = 1;
                temp = word[i];
            }
        }

        if(mp.find(temp) != mp.end()) {
            mp[temp] += cnt - 1;
        } else mp[temp] = cnt;

        int ans = 0;
        for(auto [key, value]: mp) {
            if(value > 1) {
                ans += (value - 1);
            }
        }
        return ans + 1;
    }
};
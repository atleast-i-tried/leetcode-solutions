class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;

        for (auto it : matches) {
            mp[it[1]]++;
        }

        vector<int> temp1, temp2;
        for (auto [key, value] : mp) {
            if (value == 1) temp1.push_back(key);
        }

        set<int> st;
        for (auto it : matches) {
            if (mp.find(it[0]) == mp.end()) {
                st.insert(it[0]);
            }
        }

        for (auto it : st) {
            temp2.push_back(it);
        }

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        ans.push_back(temp2);
        ans.push_back(temp1);

        return ans;
    }
};

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        int rem = s.size() % k;
        if (rem != 0) {
            s += string(k - rem, fill);
        }

        vector<string> ans;

        for (int i = 0; i < s.size(); i += k) {
            ans.push_back(s.substr(i, k));
        }

        return ans;
    }
};

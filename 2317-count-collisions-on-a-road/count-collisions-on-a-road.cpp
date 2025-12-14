class Solution {
public:
    int countCollisions(string s) {
        int ans = 0;
        stack<char> st;

        int k = 0;
        while (k < s.size() && s[k] == 'L') k++;

        for (int i = k; i < s.size(); i++) {
            if (s[i] == 'S') {
                if (!st.empty()) {
                    ans += st.size();
                    while (!st.empty()) st.pop();
                }
                continue;
            }

            bool whileRan = false;

            while (!st.empty() && s[i] == 'L') {
                st.pop();
                ans++;
                whileRan = true;
            }

            if (whileRan) {
                ans++;
                continue;
            }

            if (s[i] == 'R') st.push('R');
            else if (s[i] == 'L') ans++;
        }
        return ans;
    }
};

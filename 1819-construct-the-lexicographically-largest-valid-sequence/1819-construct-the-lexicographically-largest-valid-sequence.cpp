class Solution {
public:
    bool helper(int i, int n, vector<int>& ans, vector<bool>& vis) {
        if (i >= ans.size()) {
            return true;
        }

        if (ans[i] != -1) {
            return helper(i + 1, n, ans, vis);
        }

        for (int curnum = n; curnum >= 1; curnum--) {  
            if (!vis[curnum]) {
                vis[curnum] = true;
                ans[i] = curnum;

                if (curnum == 1) {
                    if (helper(i + 1, n, ans, vis)) return true;
                } else {
                    int j = i + curnum;  
                    if (j < ans.size() && ans[j] == -1) {
                        ans[j] = curnum;
                        if (helper(i + 1, n, ans, vis)) return true;
                        ans[j] = -1;  
                    }
                }

                // Backtrack by undoing
                vis[curnum] = false;
                ans[i] = -1;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);
        vector<bool> vis(n + 1, false);
        helper(0, n, ans, vis);
        return ans;
    }
};

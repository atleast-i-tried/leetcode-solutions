class Solution {
public:
    bool helper(int i, int n, vector<int>& ans, vector<int>& vis) {
        if (i == ans.size()) return true;

        if (ans[i] != -1) return helper(i + 1, n, ans, vis);

        for (int num = n; num > 0; num--) {
            if (!vis[num]) {
                vis[num] = 1;
                ans[i] = num;

                if (num == 1) {
                    if (helper(i + 1, n, ans, vis)) return true;
                } else {
                    int j = i + num;
                    if (j < ans.size() && ans[j] == -1) {
                        ans[j] = num;
                        if (helper(i + 1, n, ans, vis)) return true;
                        ans[j] = -1;   
                    }
                }

                vis[num] = 0;  
                ans[i] = -1;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);
        vector<int> vis(n + 1, 0);

        helper(0, n, ans, vis);
        return ans;
    }
};

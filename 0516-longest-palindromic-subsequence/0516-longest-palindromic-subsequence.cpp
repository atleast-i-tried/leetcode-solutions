class Solution {
public:
    int dp[1001][1001];
    int helper(int i, int j, string& s) {
        // base case
        if(i > j) return 0;
        if(i == j) return s[i] == s[j];

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = 2 + helper(i + 1, j - 1, s);
 
        return dp[i][j] =  max(helper(i + 1, j, s), helper(i, j - 1, s));
    }

    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        if(n == 1) return n;
        return helper(0, n - 1, s);
    }
};
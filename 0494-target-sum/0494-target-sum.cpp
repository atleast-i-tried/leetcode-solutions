class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalSum + d) % 2 != 0 || (totalSum + d) < 0) return 0;

        int target = (totalSum + d) / 2;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][0] = (arr[0] == 0) ? 2 : 1;  // pick or not pick
        if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

        for (int i = 1; i < n; ++i) {
            for (int t = 0; t <= target; ++t) {
                int notPick = dp[i - 1][t];
                int pick = (arr[i] <= t) ? dp[i - 1][t - arr[i]] : 0;
                dp[i][t] = pick + notPick;
            }
        }

        return dp[n - 1][target];
    }
};

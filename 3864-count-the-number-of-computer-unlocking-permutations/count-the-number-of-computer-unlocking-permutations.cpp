class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (n <= 1) return 1;

        int first = complexity[0];

        // Check if any later value violates the strict rule
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= first) {
                return 0;
            }
        }

        // Compute (n - 1)! % MOD
        long long fact = 1;
        for (int i = 2; i <= n - 1; i++) {
            fact = (fact * i) % MOD;
        }

        return (int)fact;
    }
};
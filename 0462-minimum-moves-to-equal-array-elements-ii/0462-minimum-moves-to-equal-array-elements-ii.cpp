class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int ans1 = 0, ans2 = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i == n / 2) continue;
            
            ans1 += abs(nums[i] - nums[n / 2]);
        }

        for(int i = 0; i < n; i++) {
            if(i == (n / 2) - 1) continue;
            ans2 += abs(nums[i] - nums[(n / 2) - 1]);
        }
        return min(ans1, ans2);
    }
};
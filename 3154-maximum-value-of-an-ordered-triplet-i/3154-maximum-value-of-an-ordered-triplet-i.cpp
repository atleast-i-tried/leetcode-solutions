class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        long long max_curr = nums[0], max_dip = 0, result = 0;
        for(int i = 1; i < n; ++i){
            long long x = (long long)nums[i];
            if(max_dip)
                result = max(result, max_dip*x);
            max_dip = max(max_dip, max_curr - x);
            max_curr = max(max_curr, x);
        }
        return result;
    }
};
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> a(nums.size() + 1);

        for(int i = 0; i < queries.size(); i++) {
            a[queries[i][0]]--;
            a[queries[i][1] + 1]++;
        }

        int decrement = 0;

        for(int i = 0; i < nums.size(); i++) {
            decrement += a[i];
            if((nums[i] + decrement) > 0) return false;
        }
        return true;
    }
};
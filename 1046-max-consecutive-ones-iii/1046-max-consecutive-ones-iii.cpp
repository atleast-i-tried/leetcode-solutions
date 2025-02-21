class Solution {
public:
// as soon as you start getting zeroes, start reducing k.
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxCnt = 0;

        for(int right = 0; right < n; right++) {

            while(nums[right] == 0 && k == 0 ) {
                if(nums[left] == 0) {
                    k++;
                }
                left++;
             }

            if(nums[right] == 0) {
                k--;
            }
            maxCnt = max(maxCnt, right - left + 1);
        }
        return maxCnt;
    }
};
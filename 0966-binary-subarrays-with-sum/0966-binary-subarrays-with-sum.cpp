class Solution {
private: 
    int helper(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int right = 0, left = 0, sum = 0, cnt = 0;

        for(right = 0; right < nums.size(); right++) {
            
            sum += nums[right];

            while(sum > goal) {
                sum -= nums[left];
                left++;
            }

            cnt += right - left + 1;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    } 
};


//  CALCULATE SUBARRAYS WITH SUM <= GOAL - 1
//  THEN CALCULATE SUBARRAYS WITH SUM <= GOAL 
//  THEN SUBTRACT THE TWO..
//  NORMAL MATHS, YOU LL GET THE WANTED RESULT
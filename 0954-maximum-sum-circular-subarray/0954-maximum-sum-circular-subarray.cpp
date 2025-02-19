class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int curMin = 0;
        int curMax = 0;
        int totalSum = 0;

        for(int i: nums) {
            totalSum += i;

            if(curMax < 0) {
                curMax = 0;
            }
            curMax += i;
            maxSum = max(curMax, maxSum);

            if(curMin > 0) {
                curMin = 0;
            }
            curMin += i;
            minSum = min(curMin, minSum);
        } 

        if(totalSum == minSum) return maxSum; // all negative case, in that case return the smallest negative

        return max(maxSum, totalSum - minSum);
    }
}; 

// think about it as a defected pipe
// if a pipe is defective, we remove the defective part right, since we need circular sum, means we the subarray can be either from between or both the ends, for between classic kadane works, for both ends, remove defected pipe, that means minSum thing
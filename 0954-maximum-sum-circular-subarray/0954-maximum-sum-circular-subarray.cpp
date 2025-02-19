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
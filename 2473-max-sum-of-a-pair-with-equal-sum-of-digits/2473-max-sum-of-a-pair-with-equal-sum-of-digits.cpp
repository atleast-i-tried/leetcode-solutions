class Solution {
public:
    int maximumSum(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        int maxSum = -1;

        for(int i: nums) {
            string temp = to_string(i);
            int digitsum = 0;
            for(char ch: temp) {
                digitsum += ch - '0';
            }
            pq.push({digitsum, i});
        }

        int prevDigitSum = -1;
        int prevNum = -1;

        while (!pq.empty()) {
            auto [digitSum, num] = pq.top();
            pq.pop();

            if (digitSum == prevDigitSum) {  
                maxSum = max(maxSum, prevNum + num);
            }

            prevDigitSum = digitSum;
            prevNum = num;
        }

        return maxSum;
    }
};
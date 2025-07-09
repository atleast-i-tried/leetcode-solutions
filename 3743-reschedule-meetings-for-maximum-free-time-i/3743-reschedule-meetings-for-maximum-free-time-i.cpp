class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int res = 0, left = 0, blocked = 0;

        for(int i = 0; i < n; ++i) {
            res = max(res, (startTime[i] - left) - blocked);
            blocked += endTime[i] - startTime[i];
            if(i >= k) {
                int j = i - k;
                left = endTime[j];
                blocked -= endTime[j] - startTime[j];
            }
        }

        res = max(res, (eventTime - left) - blocked);
        return res;
    }
};
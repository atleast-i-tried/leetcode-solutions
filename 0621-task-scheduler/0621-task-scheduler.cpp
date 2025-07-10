class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mp;
        int totalTasks = tasks.size();
        int maxFreq = 0, maxFreqTasks = 0;

        for(char c: tasks) {
            maxFreq = max(maxFreq, ++mp[c]);
        }

        for(auto [key, value]: mp) {
            if(value == maxFreq) {
                maxFreqTasks++;
            }
        }

        return max(((n + 1) * ( maxFreq - 1)) + maxFreqTasks, totalTasks);
    }
};



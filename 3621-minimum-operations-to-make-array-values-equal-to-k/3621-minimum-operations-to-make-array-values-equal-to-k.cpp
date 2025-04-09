class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // if(nums.size() == 1 && nums[0] < k) return -1;
        unordered_set<int> st(nums.begin(), nums.end());

        int cnt = 0;
        for (int key : st) {
            if (key > k) cnt++;
        }

        // if(cnt == st.size()) return cnt;

        if(cnt == st.size() - 1 && st.find(k) != st.end()) return cnt;
        return -1;
    }
};
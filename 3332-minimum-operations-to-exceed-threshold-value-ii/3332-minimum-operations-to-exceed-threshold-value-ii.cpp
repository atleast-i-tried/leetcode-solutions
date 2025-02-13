class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq; 
        int cnt = 0;

        for(int i : nums) {
            pq.push(i);
        }

        while(pq.size() > 1) { 
            
            if(pq.top() >= k) break;

            cnt++;
            long long x = pq.top(); 
            pq.pop();
            long long y = pq.top(); 
            pq.pop();

            long long res = x * 2 + y; 
            pq.push(res);
        }
        return cnt;
    }
};

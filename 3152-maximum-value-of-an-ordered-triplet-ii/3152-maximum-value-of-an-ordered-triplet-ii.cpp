 

class Solution {
public:
    long long maximumTripletValue(vector<int>& arr) {
        long long max_num = 0;
        long long max_diff = 0;
        long long ans = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(i >= 2) {
                ans = max(ans, max_diff * arr[i]);
            }

            if(i >= 1) {
                max_diff = max(max_diff, max_num - arr[i]);
            }
            
            max_num = max(max_num, (long long)arr[i]); 
        }
        return ans;
    }
};

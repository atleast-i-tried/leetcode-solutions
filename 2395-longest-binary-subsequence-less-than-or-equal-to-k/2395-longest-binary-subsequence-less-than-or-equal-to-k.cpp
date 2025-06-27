class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = 0, n=s.size();
        for(auto u : s)
            if(u=='0')  len++;
        
        long long count = 0, val = 0;
        for(int i = 0; i<32 and i<n; i++){
            if(s[n-i-1] == '1'){
                long long temp = pow(2, i);
                if(temp > k)
                    break; 
                k -= temp;
                len++;
            }
        }
        return len;
    }
};

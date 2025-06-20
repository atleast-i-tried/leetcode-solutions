class Solution {
public:
    int maxDistance(string s, int k) {

        int cnt = 0, ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        for (char ch : s) {
            
            if (ch == 'N') north++;
            else if (ch == 'S') south++;
            else if (ch == 'E') east++;
            else if (ch == 'W') west++;

            int x = abs(north - south);
            int y = abs(east - west);

            int curMax = x + y;
            int maxDis = curMax + min(2 * k, cnt + 1 - curMax);
            ans = max(ans, maxDis);
            cnt++;
        }
 
        

        return ans;  
    }
};
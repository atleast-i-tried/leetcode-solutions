class Solution {
public:
// himalayas, jk, slope concept

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;

        while(i < n) {
            // just add 1 if there's no slope, no candies
            if(ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
            }
            // keep adding 1 + 2 + 3 + 4 and so on while climbing
            int peak = 1;
            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            // keep adding 1 + 2 + 3 ... again while going down
            int down = 0;
            while(i < n && ratings[i] < ratings[i - 1]) {
                down++;
                sum += down;
                i++;
            }
            // basically at every peak we're checking if, down is greater than the peak.
            // so in the end if the down is greater than the peak, the peak will probably be down, so down - peak;
            down++;
            if(down > peak) {
                sum += down - peak;
            }
        }
        return sum;
    }
};
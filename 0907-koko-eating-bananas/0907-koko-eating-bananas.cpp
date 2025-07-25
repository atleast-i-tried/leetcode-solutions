class Solution {
public:


    bool possible(vector<int>& piles, int mid, int h) {
        for(int i = 0; i < piles.size(); i++) {
            h -= piles[i] % mid ? (piles[i] / mid) + 1 : piles[i] / mid;
        }
        return h >= 0;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1000000000;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(possible(piles, mid, h)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
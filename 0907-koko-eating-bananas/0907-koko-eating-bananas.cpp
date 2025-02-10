class Solution {
public:

    bool possible(vector<int>& piles, int mid, int h) {
        for (int i = 0; i < piles.size(); i++) {
            h -= (piles[i] / mid) + (piles[i] % mid != 0);
            if (h < 0) return false; 
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (possible(piles, mid, h)) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        return left;
    }
};
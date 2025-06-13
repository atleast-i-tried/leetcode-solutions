class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums[0];
        int ans = high; 

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool possible(vector<int>& nums, int p, int mid) {
        int count = 0;
        int i = 0;

        while (i < nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }

        return count >= p;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int start = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(target <= nums[mid]) { // for first : equal wale case me eliminate right side of array
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if(nums[mid] == target) start = mid;
        }

        low = 0;
        high = nums.size() - 1;
        int end = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(target >= nums[mid]) { // for last : equal wale case me eliminate left side of array
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            if(nums[mid] == target) end = mid;
        }

        return {start, end};
    }
};
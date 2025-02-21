class Solution {
public:


// cyclic sort
// keep swapping till a element reach its desired position, and then traverse to see which element isnt in their desired postion, return that element as answer
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // for(int i = 0; i < n; i++) {
        //     if(nums[i] <= 0 || nums[i] > n) {
        //         nums[i] = n + 1;
        //     }
        // }

        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1; // convert to 1 base
            }
        }
        return n + 1;
    }
}; 
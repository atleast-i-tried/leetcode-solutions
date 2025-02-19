class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//1. Find Break Point
//2. Find number smallest from array but greater than Break point number
//3. Place remaining in sorted order
        int n = nums.size();
        int index = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for(int i = n - 1; i > index; i--) {
                if(nums[i] > nums[index]) {
                    cout << nums[i] << " " << nums[index] << endl;
                    swap(nums[i], nums[index]);
                    break;
                }
            }

            sort(nums.begin() + index + 1, nums.end());
        }
    }
};
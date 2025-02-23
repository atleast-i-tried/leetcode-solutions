class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2;

        for(int j = 2; j < nums.size(); j++) {
            
            if(nums[j] != nums[i - 2]) {
                nums[i] = nums[j]; 
                i++;    
            }
            
        }
        return nums.size() <= 2 ? nums.size() : i;
    }
};
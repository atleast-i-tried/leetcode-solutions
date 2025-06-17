class Solution {
public:


    void subset(int index, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans) { 
        ans.push_back(temp);
        for(int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            subset(i + 1, temp, nums, ans);
            temp.pop_back();
        }     
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        subset(0, temp, nums, ans);
        return ans;
    }
};
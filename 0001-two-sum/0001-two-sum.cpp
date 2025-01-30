class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> mainAns;
        map<int , int> ans;
        for(int i = 0; i<n; i++){
            int a = nums[i];
            int b = target - a;
            if(ans.find(b) != ans.end()){
                 
                mainAns.push_back(i);
                mainAns.push_back(ans[b]);
            }
            ans[a] = i;
            
            
        }
        return mainAns;


    }
};
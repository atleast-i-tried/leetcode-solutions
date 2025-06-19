class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, candidates, target, 0, temp);
        return ans;
    }

private: 
    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, int target, int idx, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;  
            temp.push_back(candidates[i]);
            backtrack(ans, candidates, target - candidates[i], i, temp); 
            temp.pop_back();
        }
    }
};

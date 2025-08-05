class Solution {
public:
    void helper(TreeNode* root, vector<string>& nums, string temp) {
        if(!root) return;

        temp += to_string(root->val);

        if(!root->left && !root->right) {
            nums.push_back(temp);
            return;
        }

        helper(root->left, nums, temp);
        helper(root->right, nums, temp);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<string> nums;
        helper(root, nums, "");

        for(auto& it: nums) {
            sum += stoi(it);
        }
        return sum;
    }
};

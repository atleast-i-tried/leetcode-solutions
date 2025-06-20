class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                
                temp.push_back(cur->val);
                
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};

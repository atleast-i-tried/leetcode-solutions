/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // int helper(TreeNode* root, int& ans) {
    //     if(!root) return 0;

        
    // }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = root;
        int cnt = 0;

        while(!q.empty()) {
            cnt++;
            int size = q.size();
            while(size--) {
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                if(!q.front()->left && !q.front()->right) {
                    return cnt;
                }
                q.pop();
            }
        }
        return 0;
    } 
};
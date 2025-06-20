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
    int helper(TreeNode* root) {
        if(!root) return 0;

        int leftt = helper(root->left);
        int rightt = helper(root->right);

        if(leftt == -1 || rightt == -1 || abs(leftt - rightt) > 1) return -1;

        return max(leftt, rightt) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;   
    }
};
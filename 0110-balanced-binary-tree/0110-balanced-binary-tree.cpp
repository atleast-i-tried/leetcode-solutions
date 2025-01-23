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
    int Depth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int maxLeft = Depth(root->left);
        int maxRight = Depth(root->right);
        if(maxLeft == -1 || maxRight == -1 || abs(maxLeft - maxRight) > 1) return -1;
        return max(maxLeft, maxRight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(Depth(root) == -1) return false;
        return true;
    }
};
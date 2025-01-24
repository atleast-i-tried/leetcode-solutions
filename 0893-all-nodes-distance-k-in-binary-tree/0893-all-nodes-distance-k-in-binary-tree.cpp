/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// HINTS:
// 1. Use a map to store ancestor of each node via BFS 4

// 2. After storing ancestors, do classic BFS to the main tree, for every node, go up, left and right, and keep increasing the distance by 1, as soon as the distance equals k, break out

// 3. Use a visited map, (in this question, you need to go back to parent node, right, if you wont keep a visited array, for example 1. when you are at 5, you will go to left, right, and up, similarly when you are at 2, you'll go left, right and up, but when you go up from 2, you will reach 5 again, which is already traversed, so dont need to take it inside the queue again, hence we use visited)



class Solution {
public:
    void helper(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& reverse) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            
            int size = q.size();
            while(size--) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left) {
                    q.push(front->left);
                    reverse[front->left] = front;
                }
                if (front->right) {
                    q.push(front->right);
                    reverse[front->right] = front;
                }
            }
            
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> reverse;
        helper(root, reverse);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;
        
        while(!q.empty()) {
            int size = q.size();
            if(distance++ == k) break;
            while(size--) {
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]) {
                    q.push(front->right );
                    visited[front->right] = true;
                }
                if(reverse[front] && !visited[reverse[front]]) {
                    q.push(reverse[front]);
                    visited[reverse[front]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
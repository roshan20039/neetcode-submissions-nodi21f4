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
    void dfs(TreeNode* root, int maxval, int &goodnodes) {
        if(!root) return;
        if(root->val >= maxval) {
            goodnodes += 1;
            maxval = root->val;
        }
        dfs(root->left, maxval, goodnodes);
        dfs(root->right, maxval, goodnodes);                 
    }
    int goodNodes(TreeNode* root) {
            int goodnodes = 0;
            dfs(root, -1000, goodnodes);
            return goodnodes;
    }
};

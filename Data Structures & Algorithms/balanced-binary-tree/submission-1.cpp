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

    pair<int,int> dfs(TreeNode* root) {
        if(!root) {
            return {1, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int height = 1 + max(left.second, right.second);
        int balanced = abs(left.second-right.second) <= 1 and left.first and right.first;
        return {balanced, height};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};

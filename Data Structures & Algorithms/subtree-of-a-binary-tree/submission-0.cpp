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
    bool matchtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot) return true;
        if(!root or !subRoot) return false;
        bool left = false, right = false;
        if(root->val == subRoot->val) {
            left = matchtree(root->left, subRoot->left);
            right = matchtree(root->right, subRoot->right);
        } else {
            return false;
        }
        return left and right;
    }
    void dfs(TreeNode* root, TreeNode* subRoot, bool &match) {
        if(!root) return;
        if(root->val == subRoot->val) {
            if (matchtree(root, subRoot)) match = true;
        }
        dfs(root->left, subRoot, match);
        dfs(root->right, subRoot, match);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool match = false;
        dfs(root, subRoot, match);
        return match;
    }
};

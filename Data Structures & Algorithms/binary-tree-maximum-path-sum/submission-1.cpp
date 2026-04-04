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
    int getmax(TreeNode* root) {
        if(!root) return 0;
        int left = getmax(root->left);
        int right = getmax(root->right);
        int maxsum = root->val + max(left, right);
        return max(0, maxsum);
    }
    int dfs(TreeNode* root, int &ans) {
        if(!root) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        ans = max(ans, left + right + root->val);
        return max(0, root->val + max(left, right));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};
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
    int ans = 0;
    int finddiameter(TreeNode* root) {
        if(!root) return 0;      
        int leftdiameter = finddiameter(root->left);
        int rightdiameter = finddiameter(root->right);
        ans = max(ans, leftdiameter+rightdiameter);
        return 1+max(leftdiameter,rightdiameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        finddiameter(root);
        return ans;
    }
};

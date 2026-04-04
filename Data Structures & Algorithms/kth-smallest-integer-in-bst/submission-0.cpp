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
    void inorder(TreeNode* root, vector<int> &inorderlist) {
        if(!root) return;
        inorder(root->left, inorderlist);
        inorderlist.push_back(root->val);
        inorder(root->right, inorderlist);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderlist;
        inorder(root, inorderlist);
        return inorderlist[k-1];
    }
};

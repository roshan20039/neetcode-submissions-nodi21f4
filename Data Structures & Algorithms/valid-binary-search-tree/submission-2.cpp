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
    vector<int> inorder;
    int i = 0;
    bool dfs(TreeNode* root) {
        if(!root) return true;
        if(!dfs(root->left)) return false;
        if(inorder.size() == 0) {
            inorder.push_back(root->val);
            i++;
        } else {
            if(root->val > inorder[i-1]) {
                inorder.push_back(root->val);
                i++;
            } else {
                return false;
            }
        }
        return dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};

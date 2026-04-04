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
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        TreeNode *cur = root;
        while(cur) {
            if(cur->left == nullptr) {
                count--;
                if(count == 0) {
                    return cur->val;
                }
                cur=cur->right;
            } else {
                TreeNode *ip = cur->left;
                while(ip->right and ip->right != cur) {
                    ip = ip->right;
                }
                if(ip->right == nullptr) {
                    ip->right = cur;
                    cur = cur->left;
                } else {
                    ip->right = nullptr;
                    count--;
                    if(count == 0) return cur->val;
                    cur = cur->right;
                }
            }
        }
        return -1;
    }
};

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
    int find_root_pos(vector<int>& inorder,int left, int right, int val) {
        for(int i = left; i <= right; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int preleft, vector<int>& inorder, int inleft, int inright, unordered_map<int, int> inorder_map) {
        if(inleft > inright) {
            return nullptr;
        }
        int index = inorder_map[preorder[preleft]];
        TreeNode *root = new TreeNode(inorder[index]);
        root->left = buildTreeHelper(preorder, preleft+1, inorder, inleft, index-1, inorder_map);
        root->right = buildTreeHelper(preorder, preleft + (index - inleft) + 1, inorder, index+1, inright, inorder_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> inorder_map;
            for(int i = 0; i < inorder.size(); i++) {
                inorder_map[inorder[i]] = i;
            }
            return buildTreeHelper(preorder, 0, inorder, 0, inorder.size()-1, inorder_map);
    }
};
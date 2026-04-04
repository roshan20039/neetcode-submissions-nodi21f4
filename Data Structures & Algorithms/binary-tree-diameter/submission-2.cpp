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
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *cur = root, *prev = nullptr;
        unordered_map<TreeNode*, pair<int, int>> node_dimensions_map;
        node_dimensions_map[nullptr] = {0, 0};
        while(cur or !st.empty()) {
            while(cur) {
                st.push(cur);
                cur=cur->left;
            }
            cur = st.top();
            if(!cur->right or cur->right == prev) {
                st.pop();
                auto[leftheight, leftdiameter] = node_dimensions_map[cur->left];
                auto[rightheight, rightdiameter] = node_dimensions_map[cur->right];
                int height = 1 + max(leftheight, rightheight);
                int diameter = max(leftheight+rightheight, max(leftdiameter, rightdiameter));
                node_dimensions_map[cur] = {height, diameter};
                prev = cur;
                cur = nullptr;
            } else {
                cur=cur->right;
            }
        }
        return node_dimensions_map[root].second;
    }
};

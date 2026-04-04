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
        if(!root) return true;
        //return dfs(root).first;
        unordered_map<TreeNode*, int> node_height_map;
        stack<TreeNode*> st;
        st.push(root);
        node_height_map[nullptr] = 0;
        while(!st.empty()) {
            TreeNode *cur = st.top();
            if(cur->left and node_height_map.find(cur->left) == node_height_map.end()) {
                st.push(cur->left);
                cur=cur->left;
            } else if(cur->right and node_height_map.find(cur->right) == node_height_map.end()) {
                st.push(cur->right);
                cur=cur->right;                
            } else {
              st.pop();
              int left = node_height_map[cur->left];
              int right = node_height_map[cur->right];
              node_height_map[cur] = 1 + max(left, right);
              if(abs(left-right) > 1) return false;
            }
        }
        return true;
    }
};

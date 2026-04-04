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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        vector<vector<int>> lot_list;
        while(!q.empty()) {
            auto[node, depth] = q.front();
            q.pop();
            if(lot_list.size() == depth) {
                lot_list.push_back({});
            }
            lot_list[depth].push_back(node->val);
            if(node->left) q.push({node->left, depth+1});
            if(node->right) q.push({node->right, depth+1});
        }
        return lot_list;
    }
};

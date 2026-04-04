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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(!root) return 0;
        q.push({root,1});
        int ans = 0;
        while(!q.empty()) {
            auto pr = q.front();
            q.pop();
            TreeNode *node = pr.first;
            int depth = pr.second;
            ans = max(ans, depth);
            if(node->left) {
                q.push({node->left, depth+1});
            }
            if(node->right) {
                q.push({node->right, depth+1});
            }
        }
        return ans;
    }
};

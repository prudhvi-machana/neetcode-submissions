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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int cnt = 0;
        while(!q.empty()){
            auto[node, curr] = q.front();
            q.pop();
            if(node->val >= curr){
                cnt++;
                curr = node->val;
            }
            if(node->left) q.push({node->left, curr});
            if(node->right) q.push({node->right, curr});
        }
        return cnt;
    }
};

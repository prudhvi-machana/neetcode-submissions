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
            pair<TreeNode*, int>  node = q.front();
            q.pop();
            int curr = node.second;
            if(node.first->val >= curr){
                cnt++;
                curr = node.first->val;
            }
            if(node.first->left) q.push({node.first->left, curr});
            if(node.first->right) q.push({node.first->right, curr});
        }
        return cnt;
    }
};

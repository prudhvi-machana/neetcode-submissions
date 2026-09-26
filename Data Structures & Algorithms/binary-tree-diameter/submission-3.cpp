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
    int find(TreeNode* root, int& res){
        if(!root)return 0;
        int left = find(root->left, res);
        int right = find(root->right, res);
        res = max(res, left+right);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        find(root, res);
        return res;
    }
};

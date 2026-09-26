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
        if(!root->left && !root->right)return 0;
        int curr = 0;
        if(!root->right){
            curr = 1+find(root->left, res);
            res = max(res, curr);
            return curr;
        }
        if(!root->left){
            curr = 1+find(root->right, res);
            res = max(res, curr);
            return curr;
        }

        curr = 2 + find(root->left, res) + find(root->right, res);
        res = max(res, curr);
        return 1+max(find(root->left, res), find(root->right, res));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        find(root, res);
        return res;
    }
};

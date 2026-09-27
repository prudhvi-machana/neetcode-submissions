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
    bool find(TreeNode* root, int low, int high){
        if(!root) return true;

        if(root->val <= low || root->val >= high){
            return false;
        }

        return find(root->left, low, root->val) && find(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return find(root, INT_MIN, INT_MAX);
    }
};

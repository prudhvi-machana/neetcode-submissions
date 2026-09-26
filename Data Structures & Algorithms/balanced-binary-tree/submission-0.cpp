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
    int find(TreeNode* root){
        if(!root) return 0;
        int left = find(root->left);
        int right = find(root->right);
        if(left<0 || right<0 ||abs(left-right) > 1){
            return -1;
        }
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(find(root) < 0){
            return false;
        }
        return true;
    }
};

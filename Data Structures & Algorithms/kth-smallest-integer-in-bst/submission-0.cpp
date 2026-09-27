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
    void find(TreeNode* root, int &k, int& v){
        if(!root || k==0) return;

        find(root->left, k, v);
        k--;
        if(k==0){
            v = root->val;
            return;
        }

        find(root->right, k, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        int v = -1;
        find(root, k, v);
        return v;
    }
};

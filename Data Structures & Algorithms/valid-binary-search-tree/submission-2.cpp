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
    vector<int> find(TreeNode* root){
        if(!root) return {1, INT_MAX, INT_MIN};
        
        vector<int> l = find(root->left);
        vector<int> r = find(root->right);

        if(!l[0] || !r[0]) return {0,0,0};

        if(l[2] >= root->val || root->val >= r[1]){
            return {0,0,0};
        }

        int cmin = min(root->val, l[1]);
        int cmax = max(root->val, r[2]);
        return {1, cmin, cmax};
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return find(root)[0];
    }
};

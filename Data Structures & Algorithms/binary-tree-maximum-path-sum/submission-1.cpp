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
    int res = 0;
    int maxPathSum(TreeNode* root) {
        res = root->val;
        find(root);
        return res;
    }

    int find(TreeNode* root){
        if(!root) return 0;
        int l = find(root->left);
        int r = find(root->right);
        l = max(0,l);
        r = max(0,r);
        cout<<l<<" "<<r<<endl;
        int ans = root->val;
        ans += max(l,r);

        res = max(res, root->val + l + r);
        return ans;
    }
};

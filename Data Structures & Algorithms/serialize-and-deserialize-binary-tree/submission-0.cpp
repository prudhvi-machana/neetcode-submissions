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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "null";
        }

        queue<TreeNode*> st;
        st.push(root);
        TreeNode* tmp = new TreeNode(-1001);
        string s = "";
        while(!st.empty()){
            int size = st.size();
            for(int i=0;i<size;i++){
                TreeNode* node = st.front();
                st.pop();
                if(node == tmp){
                    s += "null,";
                    continue;
                }
                s += to_string(node->val) + ',';

                if(node->left){
                    st.push(node->left);
                }else{
                    st.push(tmp);
                }

                if(node->right){
                    st.push(node->right);
                }else{
                    st.push(tmp);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string x = "";
        for(char c: data){
            if(c == ','){
                tokens.push_back(x);
                x = "";
            }else{
                x += c;
            }
        }

        if(tokens.empty() || tokens[0] == "null"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        deque<TreeNode*> dq;
        dq.push_back(root);
        int i=1;
        while(!dq.empty() && i<tokens.size()){
            TreeNode* curr = dq.front();
            dq.pop_front();
            if(tokens[i] != "null"){
                curr->left = new TreeNode(stoi(tokens[i]));
                dq.push_back(curr->left);
            }
            i++;
            if(i>= tokens.size()) break;
            if(tokens[i] != "null"){
                curr->right = new TreeNode(stoi(tokens[i]));
                dq.push_back(curr->right);
            }
            i++;
        }

        return root;
    }
};

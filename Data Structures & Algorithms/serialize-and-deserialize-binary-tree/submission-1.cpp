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
            return "N";
        }
        vector<string> res;
        ser(root, res); 
        int n = res.size();
        string s = "";
        for(int i=0;i<n;i++){
            if(i!= n-1) s += res[i] + ",";
            else s += res[i];
        }
        return s;
    }

    void ser(TreeNode* root, vector<string>& res){
        if(!root){
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        ser(root->left, res);
        ser(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data[0] == 'N') return nullptr;

        vector<string> tokens;
        string x = "";
        for(char c : data){
            if(c == ','){
                tokens.push_back(x);
                x = "";
            }else{
                x += c;
            }
        }
        if(!x.empty()){
            tokens.push_back(x);
        }
        int i=0;
        return deser(tokens, i);
    }

    TreeNode* deser(vector<string>& tokens, int& i){
        if(i==tokens.size() || tokens[i] == "N"){
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tokens[i]));
        i++;
        node->left = deser(tokens, i);
        node->right = deser(tokens, i);

        return node;
    }
};

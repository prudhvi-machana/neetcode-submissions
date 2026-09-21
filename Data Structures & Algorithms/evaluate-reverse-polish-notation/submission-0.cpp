class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i=0;i<n;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                int z;
                if(tokens[i] == "+")z = x+y;
                if(tokens[i] == "-")z = y-x;
                if(tokens[i] == "*")z = x*y;
                if(tokens[i] == "/")z = y/x;
                st.push(z);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

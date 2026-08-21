class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string res ="";
        for(int i=0;i<n;i++){
            string s = strs[i];
            int m = s.size();
            res += to_string(m) + '|' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int n = s[i]-'0';
            i++;
            while(s[i]!= '|'){
                n = n*10 + s[i] - '0';
                i++;
            }
            i++;
            string tmp = "";
            for(int j=0;j<n;j++){
                tmp += s[i];
                i++;
            }
            res.push_back(tmp);
        }
        return res;
    }
};

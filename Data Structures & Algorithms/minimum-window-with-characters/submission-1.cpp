class Solution {
public:
    bool okay(map<char,int>& need, map<char,int>& curr){
        for(auto &it : need){
            char c = it.first;
            int req = it.second;
            if(curr[c] < req){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n < m)return "";

        map<char, int> need, curr;
        for(int i=0;i<m;i++){
            need[t[i]]++;
        }

        int l=0, fl = -1, fr = n-1;
        for(int r=0; r<n; r++){
            curr[s[r]]++;

            while(okay(need, curr)){
                if(fr-fl > r-l){
                    fl = l;
                    fr =r;
                }
                curr[s[l]]--;
                l++;
            }
        }

        string res = "";
        if(fl == -1)return res;
        for(int k=fl; k<=fr; k++){
            res += s[k];
        }
        return res;
    }
};

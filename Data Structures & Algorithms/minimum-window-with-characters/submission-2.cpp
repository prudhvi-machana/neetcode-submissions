class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n < m)return "";

        map<char, int> need, curr;
        for(int i=0;i<m;i++){
            need[t[i]]++;
        }

        int have = 0, req = need.size();
        int l=0, fl = -1, fr = n-1;
        for(int r=0; r<n; r++){
            curr[s[r]]++;
            if(need.count(s[r]) && need[s[r]] == curr[s[r]]){
                have++;
            }
            while(have == req){
                if(fr-fl > r-l){
                    fl = l;
                    fr =r;
                }
                if(need[s[l]] == curr[s[l]]){
                    have--;
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

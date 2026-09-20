class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n>m)return false;
        map<char,int> mp, mp1;
        for(int i=0;i<n;i++){
            mp[s1[i]]++;
        }
        
        int i=0;
        for(int j=0; j<m; j++){
            mp1[s2[j]]++;

            if(j-i+1 > n){
                mp1[s2[i]]--;
                if(mp1[s2[i]] == 0){
                    mp1.erase(s2[i]);
                }
                i++;
            }

            if(j-i+1 == n && mp1 == mp){
                return true;
            }
        }
        return false;
    }
};

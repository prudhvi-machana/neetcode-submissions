class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int mx = 0, res = 0;
        int i=0, j=0;
        while(j<n){
            freq[s[j]-'A']++;
            if(freq[s[j]-'A'] > freq[mx]){
                mx = s[j]-'A';
            }
            while(k < (j-i+1 - freq[mx])){
                freq[s[i]-'A']--;
                if(mx == s[i]-'A'){
                    for(int m=0;m<26;m++){
                        if(freq[m] > freq[mx]){
                            mx = m;
                        }
                    }
                }
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int mx = 0, res = 0;
        int i=0, j=0;
        while(j<n){
            freq[s[j]-'A']++;
            mx = max(mx, freq[s[j]-'A']);
            while(k < (j-i+1 - mx)){
                freq[s[i]-'A']--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0)return 0;
        unordered_map<char,int> mp;
        int len =1;
        int i=0, j=1;
        mp[s[i]] = i;
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]] = j;
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};

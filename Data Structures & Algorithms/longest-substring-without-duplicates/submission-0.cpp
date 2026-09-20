class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0)return 0;
        map<int,int> mp;
        int len =1;
        int i=0, j=1;
        mp[s[i]]++;
        while(j<n){
            while(mp.find(s[j]) != mp.end()){
                mp.erase(s[i]);
                i++;
            }
            mp[s[j]]++;
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};

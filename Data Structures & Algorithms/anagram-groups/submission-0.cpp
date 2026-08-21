class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            int m=strs[i].size();
            vector<int> freq(26,0);

            for(int j=0;j<m;j++){
                freq[strs[i][j]-'a']++;
            }

            mp[freq].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto x : mp){
            res.push_back(x.second);
        }
        return  res;
    }
};

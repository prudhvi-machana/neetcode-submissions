class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int n = nums.size();
        vector<vector<int>> fr(n+1);
        for(auto &x: mp){
            fr[x.second].push_back(x.first);
        }
        vector<int> res;
        for(int i= n;i>0;i--){
            for(int j=0;j<fr[i].size();j++){
                res.push_back(fr[i][j]);
                if(res.size()==k){
                    return res;
                }
            }
        }
    }
};

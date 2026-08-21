class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto &x: mp){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for(int i=v.size()-1;i>= (int)v.size()-k;i--){
            res.push_back(v[i].second);
        }
        return res;
    }
};

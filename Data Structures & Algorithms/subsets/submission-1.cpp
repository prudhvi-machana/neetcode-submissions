class Solution {
public:
    void find(int i, int n, vector<int> tmp, vector<int>& nums, vector<vector<int>>& res){
        if(i==n){
            res.push_back(tmp);
            return;
        }
        find(i+1, n, tmp, nums, res);
        tmp.push_back(nums[i]);
        find(i+1, n, tmp, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = nums.size();
        find(0, n, tmp, nums, res);
        return res;
    }
};

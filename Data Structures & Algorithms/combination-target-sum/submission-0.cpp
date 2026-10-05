class Solution {
public:
    void find(int i, int n, int sum, int target, vector<int>& nums, vector<int>& tmp, set<vector<int>>& res){
        if(sum > target) return;
        if(i==n){
            if(sum == target){
                res.insert(tmp);
            }
            return;
        }

        tmp.push_back(nums[i]);
        find(i, n, sum+nums[i], target, nums, tmp, res);
        find(i+1, n, sum+nums[i], target, nums, tmp, res);
        tmp.pop_back();
        find(i+1, n, sum, target, nums, tmp, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> tmp;
        int n = nums.size();
        find(0, n, 0, target, nums, tmp, res);
        vector<vector<int>> ans;
        for(auto& it: res){
            ans.push_back(it);
        }
        return ans;
    }
};

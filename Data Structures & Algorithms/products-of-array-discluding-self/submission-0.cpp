class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pr(n), sf(n);

        pr[0] = nums[0];
        for(int i=1;i<n;i++){
            pr[i] = pr[i-1]*nums[i];
        }

        sf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            sf[i] = sf[i+1]*nums[i];
        }

        vector<int> res(n);
        for(int i=0;i<n;i++){
            int tmp = 1;
            if(i>0){
                tmp = tmp*pr[i-1];
            }
            if(i<n-1){
                tmp = tmp*sf[i+1];
            }
            res[i] = tmp;
        }
        return res;
    }
};

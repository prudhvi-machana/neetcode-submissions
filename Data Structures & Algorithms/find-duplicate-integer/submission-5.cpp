class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<32;i++){
            int x=0, y=0;
            int mask = 1<<i;
            for(int j=0;j<n;j++){
                if(nums[j]&mask){
                    x++;
                }
            }
            for(int k=1;k<n;k++){
                if(k&mask){
                    y++;
                }
            }
            if(x>y){
                res = res|mask;
            }
        }
        return res;
    }
};

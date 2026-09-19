class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int l=0, r=n-1;
        int lmax = height[l], rmax = height[r];
        int ans = 0;
        while(l<r){
            if(height[l] <= height[r]){
                ans += max(0, lmax - height[l]);
                l++;
                lmax = max(lmax, height[l]);
            }else{
                ans += max(0, rmax - height[r]);
                r--;
                rmax = max(rmax, height[r]);
            }
        }
        return ans;
    }
};

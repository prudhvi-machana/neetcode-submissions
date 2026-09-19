class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref(n), suff(n);
        pref[0] = height[0];
        for(int i=1;i<n;i++){
            pref[i] = max(pref[i-1], height[i]);
        }

        suff[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1], height[i]);
        }

        int ans =0;
        for(int i=1;i<=n-2; i++){
            int h = min(pref[i-1], suff[i+1]);
            ans += max(0, h-height[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0, j=n-1;
        int ans = min(heights[i], heights[j])*(j-i);
        while(i<j){
            if(heights[i] >= heights[j]){
                j--;
            }else{
                i++;
            }
            ans = max(ans, min(heights[i], heights[j])*(j-i));
        }
        return ans;
    }
};

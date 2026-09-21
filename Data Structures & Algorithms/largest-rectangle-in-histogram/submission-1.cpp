class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> s;
        int mxarea = 0;
        for(int i=0;i<=n;i++){
            int currh = (i==n) ? 0: heights[i];
            if(!s.empty()){
                while(!s.empty() && heights[s.top()] > currh){
                    int h = heights[s.top()];
                    s.pop();
                    int w = s.empty() ? i : i - s.top() - 1;
                    mxarea = max(mxarea, h*w);
                }
            }
            if(i<n)s.push(i);
        }
        return mxarea;
    }
};

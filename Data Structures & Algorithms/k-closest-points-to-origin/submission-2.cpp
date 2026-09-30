class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> v;
        int n = points.size();
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = abs(x*x + y*y);
            v.push({d, i});
            if(v.size() > k){
                v.pop();
            }
        }

        vector<vector<int>> res;
        while(!v.empty()){
            int idx = v.top().second;
            v.pop();
            res.push_back(points[idx]);
        }
        return res;
    }
};

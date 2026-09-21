class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<double> ts;
        stack<double>s;
        vector<pair<int,int>> tmp;
        for(int i=0;i<n;i++){
            tmp.push_back({position[i], speed[i]});
        }
        sort(tmp.begin(), tmp.end());
        for(int i=0;i<n;i++){
            ts.push_back((target - tmp[i].first)/(1.0*tmp[i].second));
        }

        for(int i=n-1;i>=0; i--){
            if(s.empty()){
                s.push(ts[i]);
            }else{
                if(ts[i] > s.top()){
                    s.push(ts[i]);
                }
            }
        }
        return s.size();
    }
};

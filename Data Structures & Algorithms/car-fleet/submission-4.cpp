class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> tmp;
        for(int i=0;i<n;i++){
            tmp.push_back({position[i], speed[i]});
        }
        sort(tmp.rbegin(), tmp.rend());

        double prev = (target - tmp[0].first)/(1.0*tmp[0].second);
        int cnt = 1;
        for(int i=1;i<n; i++){
            double curr = (target - tmp[i].first)/(1.0*tmp[i].second);
            if(curr > prev){
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};

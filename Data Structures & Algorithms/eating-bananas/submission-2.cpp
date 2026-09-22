class Solution {
public:
    bool pos(int k, vector<int>& p, int h){
        long long req = 0;
        for(int i=0;i<p.size();i++){
            req += 1LL*(p[i] + k -1)/k;
        }
        return req<=1LL*h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        while(low < high){
            int mid = low + (high-low)/2;

            if(pos(mid, piles, h)){
                high = mid;
            }else{
                low = mid+1;
            }
        }

        return high;
    }
};

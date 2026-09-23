class TimeMap {
public:
    unordered_map<string,vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& tmp = mp[key];

        int low = 0, high = tmp.size();
        int idx = -1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(tmp[mid].first <= timestamp){
                idx = mid;
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return (idx==-1) ? "" : tmp[idx].second;
    }
};

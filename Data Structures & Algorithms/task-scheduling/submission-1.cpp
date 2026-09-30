class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(int i=0;i<tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }
        int mx_freq = 0;
        for(int i=0;i<26;i++){
            mx_freq = max(mx_freq, freq[i]);
        }
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(mx_freq == freq[i])cnt++;
        }

        int ans = (mx_freq-1)*(n+1) + cnt;
        ans = max(ans, (int)tasks.size());
        return ans;
    }
};

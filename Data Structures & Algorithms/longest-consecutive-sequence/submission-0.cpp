class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int mx = 0;
        for (int n : st) {
            if (st.find(n - 1) == st.end()) {
                int l = 1;
                while (st.find(n + l) != st.end()) {
                    l++;
                }
                mx = max(mx, l);
            }
        }
        return mx;
    }
};

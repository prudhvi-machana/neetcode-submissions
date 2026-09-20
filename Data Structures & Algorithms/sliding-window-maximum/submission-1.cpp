class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st;
        for(int i=0;i<k;i++){
            st.insert(nums[i]);
        }
        vector<int> res;
        res.push_back(*st.rbegin());

        int j=k;
        while(j<n){
            auto it = st.find(nums[j-k]);
            st.erase(it);
            st.insert(nums[j]);
            res.push_back(*st.rbegin());
            j++;
        }

        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        int n = prices.size();
        int minval = prices[0];
        for(int i=0;i<n;i++){
            minval = min(minval, prices[i]);
            profit = max(profit, prices[i] - minval);
        }
        return profit;
    }
};

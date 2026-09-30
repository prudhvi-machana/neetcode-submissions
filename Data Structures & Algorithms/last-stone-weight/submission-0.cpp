class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(!pq.empty() && pq.size()!=1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int z = abs(x-y);
            if(z!=0){
                pq.push(z);
            }
        }
        pq.push(0);
        return pq.top();
    }
};

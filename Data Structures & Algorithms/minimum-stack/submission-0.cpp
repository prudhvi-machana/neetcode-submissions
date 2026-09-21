class MinStack {
public:

    vector<pair<int,int>> arr;

    MinStack() {
    }
    
    void push(int val) {
        if(arr.empty()){
            arr.push_back({val, val});
        }else{
            int mn = min(val, arr.back().second);
            arr.push_back({val, mn});
        }
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};

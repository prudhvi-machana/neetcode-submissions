class MinStack {
public:

    stack<int> st, mst;

    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mst.push(val);
        }else{
            int mn = min(val, mst.top());
            st.push(val);
            mst.push(mn);
        }
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};

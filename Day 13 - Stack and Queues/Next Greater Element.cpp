vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> res(n, 0);
    if(n == 0) {
        return res;
    }
    res[n-1] = -1;
    st.push(A[n-1]);
    for(int i=n-2; i>=0; i--){
        while(!st.empty() && st.top()<=A[i]){
            st.pop();
        }
        if(st.empty()) {
            res[i] = -1;
        }
        else {
            res[i] = st.top();
        }
        st.push(A[i]);
    }
    return res;
}

int Solution::majorityElement(const vector<int> &A) {
    int count = 0;
    int element = 0;
    for(int i=0; i<A.size(); i++) {
        if(count == 0) {
            element = A[i];
        }
        if(element == A[i]) {
            count++;
        } else {
            count--;
        }
    }
    return element;
}

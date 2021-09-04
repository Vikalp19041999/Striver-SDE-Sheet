int Solution::trap(const vector<int> &A) {
    int left = 0;
    int right = A.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int trapped = 0;
    while(left <= right) {
        if(A[left] < A[right]) {
            if(A[left] >= leftMax) {
                leftMax = A[left];
            } else {
                trapped = trapped + leftMax - A[left];
            }
            left++;
        } else {
            if(A[right] >= rightMax) {
                rightMax = A[right];
            } else {
                trapped = trapped + rightMax - A[right];
            }
            right--;
        }
    }
    return trapped;
}

int Solution::atoi(const string A) {
    int sign = 1; 
    int result = 0;
    int i = 0;
    while (A[i] == ' ') { 
        i++; 
    }
    if(A[i] == '-' || A[i] == '+') {
        sign = (A[i++] == '-') ? -1 : 1; 
    }
    while (A[i] >= '0' && A[i] <= '9') {
        if(result >  INT_MAX / 10 || (result == INT_MAX / 10 && A[i] - '0' > 7)) {
            if(sign == 1) {
                return INT_MAX;
            }
            else {
                return INT_MIN;
            }
        }
        result = 10 * result + (A[i++] - '0');
    }
    return result * sign;
}

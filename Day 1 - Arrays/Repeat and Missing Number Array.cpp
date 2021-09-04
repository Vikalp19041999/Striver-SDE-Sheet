vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int A_sum = 0;
    long long int A_square = 0;
    long long int exp_sum;
    long long int exp_square;
    long long int i = 0;
    for(i=0; i<A.size(); i++){
        A_sum = A_sum + (long long int)A[i];
        A_square = A_square + (long long int)A[i]*A[i];
    }
    exp_sum = (long long int)(A.size())*(A.size()+1)/2;
    exp_square = (long long int)(A.size())*(A.size()+1)*(2*A.size()+1)/6;
    long long int diff_square = exp_square - A_square;
    long long int diff_sum = exp_sum - A_sum;
    long long int tog = diff_square/diff_sum;
    long long int missing = (tog + diff_sum)/2;
    long long int repeat = missing - diff_sum;
    vector<int> sol;
    sol.push_back((int)repeat);
    sol.push_back((int)missing);
    return sol;
}

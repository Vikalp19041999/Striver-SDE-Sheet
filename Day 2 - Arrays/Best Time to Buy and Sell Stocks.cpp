int Solution::maxProfit(const vector<int> &A) {
    int profit = 0;
    int buy = INT_MAX;
    for(int i=0; i<A.size(); i++) {
        buy = min(buy, A[i]);
        profit = max(profit, A[i] - buy);
    }
    return profit;
}

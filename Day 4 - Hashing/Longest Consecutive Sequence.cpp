int Solution::longestConsecutive(const vector<int> &A) {
    int streak = 0;
    if(A.size() == 0) {
        return 0;
    }
    set<int> hashset;
    for(int i=0; i<A.size(); i++) {
        hashset.insert(A[i]);
    }
    for(int i=0; i<A.size(); i++) {
        if(!hashset.count(A[i] - 1)) {
            int current = A[i];
            int cs = 1;
            while(hashset.count(current + 1)) {
                current = current + 1;
                cs = cs + 1;
            }
            streak = max(streak, cs);
        }
    }
    return streak;
}

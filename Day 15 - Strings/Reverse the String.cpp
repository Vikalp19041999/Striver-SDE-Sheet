string Solution::solve(string A) {
    string ans;
    int n = A.size();
    int i = 0;
    while(i<n) {
        if(!isspace(A[i])) {
            string temp = "";
            while(i<n && (!isspace(A[i]))) {
                temp+=A[i];
                i++;
            }
            string t1 = " ";
            t1+=temp;
            ans = t1+ans;
        } else {
            i++;
        }
    }
    return ans.substr(1, ans.size()-1);
}

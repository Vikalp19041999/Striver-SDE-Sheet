vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    if (A.empty()) {
        return res;
    } 
    sort(A.begin(),A.end());
    for (int i=0; i<A.size(); i++) {
        int target_3 = B - A[i];
        for (int j=i+1; j<A.size(); j++) {
            int target_2 = target_3 - A[j];
            int left = j + 1;
            int right = A.size() - 1;
            while(left < right) {
                if (A[left]+A[right] < target_2) {
                    left++;
                } else if (A[left]+A[right] > target_2) {
                    right--;
                } else {
                    vector<int> temp(4, 0);
                    temp[0] = A[i];
                    temp[1] = A[j];
                    temp[2] = A[left];
                    temp[3] = A[right];
                    res.push_back(temp);
                    while (left < right && A[left] == temp[2]) {
                        left++;
                    } 
                    while (left < right && A[right] == temp[3]) {
                        right--;
                    }
                }
            }
            while(j+1<A.size() && A[j+1] == A[j]) {
                j++;
            }
        }
        while(i+1<A.size() && A[i+1] == A[i]) {
            i++;
        }
    }
    return res;
}

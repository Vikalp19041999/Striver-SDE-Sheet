class Solution {
    public:
    int merge(long long arr[], long long temp[], int left, int mid, int right) {
        int i = left;
        int j = mid;
        int k = left;
        int count = 0;
        while((i<=mid-1) && (j<=right)) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count = count + (mid - i);
            }
        }
        while(i <= mid-1) {
            temp[k++] = arr[i++];
        }
        while(j <= right) {
            temp[k++] = arr[j++];
        }
        for(int i=left; i<=right; i++) {
            arr[i] = temp[i];
        }
        return count;
    }
    
    int merge_sort(long long arr[], long long temp[], int left, int right) {
        int count = 0;
        int mid;
        if(right > left) {
            mid = (right + left) / 2;
            count = count + merge_sort(arr, temp, left, mid);
            count = count + merge_sort(arr, temp, mid - 1, right);
            count = count + merge(arr, temp, left, mid + 1, right);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int temp[N];
        int ans = merge_sort(arr, temp, 0, N-1);
        return ans;
    }
}
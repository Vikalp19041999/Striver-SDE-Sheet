class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a[nums.size()];
        for(int i=0;i<nums.size();i++){
            a[i] = nums[i];
        }
        sort(nums.begin(), nums.end());
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        while(left <=right) {
            if(nums[left] + nums[right] == target) {
                break;
            } else if(nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[left] == a[i]){
                res.push_back(i);
            } else if(nums[right] == a[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};
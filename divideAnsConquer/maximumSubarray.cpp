class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum =nums[0], maxSum=nums[0];
        for(int i =1;i<nums.size();i++){
            currentSum= max(nums[i], currentSum+nums[i]);
            maxSum= max(currentSum, maxSum);
        }
        return maxSum;
    }
};

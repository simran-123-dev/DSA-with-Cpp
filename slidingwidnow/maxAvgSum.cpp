class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;

        // STEP 1: first window
        for(int i = 0; i < k; i++)
            windowSum += nums[i];

        int maxSum = windowSum;

        // STEP 2: slide window
        for(int i = k; i < nums.size(); i++){
            windowSum += nums[i];
            windowSum -= nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int x = 0; x < k; x++) sum += nums[x];
        int max_sum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            if (sum > max_sum) max_sum = sum;
        }
        return max_sum / (double)k;
    }
};
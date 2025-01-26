class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>& ans, int target, int sum, vector<int>& nums, int start) {
        if (sum == target) {
            ans.push_back(nums);
            return;
        }
        for (int j = start; j < candidates.size(); j++) {
            if (sum + candidates[j] <= target) {
                nums.push_back(candidates[j]);
                solve(candidates, ans, target, sum + candidates[j], nums, j);
                nums.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        solve(candidates, ans, target, 0, nums, 0);
        return ans;
    }
};

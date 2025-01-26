 class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>& ans, int target, int sum, vector<int>& nums, int i) {
        if (sum == target) {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            if (sum + candidates[j] <= target) {
                if(j>i&&candidates[j]==candidates[j-1]) continue;
                nums.push_back(candidates[j]);
                solve(candidates, ans, target, sum + candidates[j], nums, j+1);
                nums.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> nums;
        solve(candidates, ans, target, 0, nums, 0);
        return ans;
    }
};
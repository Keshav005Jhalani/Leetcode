class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_map<int, bool> hash; 
        for (int j = i; j < nums.size(); j++) {
            if (hash[nums[j]]) continue; 
            hash[nums[j]] = true;
            swap(nums[i], nums[j]);
            solve(nums, ans, i + 1);
            swap(nums[i], nums[j]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); 
        solve(nums, ans, 0);
        return ans;
    }
};

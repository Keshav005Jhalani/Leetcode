class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        } 
        for(int j=i;j<=nums.size()-1;j++){
            swap(nums[i],nums[j]);
            solve(nums,ans,i+1);
            swap(nums[i],nums[j]);

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};
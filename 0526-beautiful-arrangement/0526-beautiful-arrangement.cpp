class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>> &ans,int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        } 
        for(int j=i;j<=nums.size()-1;j++){
            if ((nums[j] % (i + 1) == 0 || (i + 1) % nums[j] == 0)) {
            swap(nums[i],nums[j]);
            solve(nums,ans,i+1);
            swap(nums[i],nums[j]);
            }
        }

    }

    int countArrangement(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans.size();
    }
};
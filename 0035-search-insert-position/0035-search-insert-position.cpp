class Solution {
public:
    int solve(vector<int>& nums, int target,int start,int end){
        int mid=(start+end)/2;
        if(nums[mid]==target) return mid;
        if(start>end) return start;
        if(nums[mid]<target) return solve(nums,target,mid+1,end);
        else return solve(nums,target,start,mid-1);
    }

    int searchInsert(vector<int>& nums, int target) {
        return solve(nums,target,0,nums.size()-1);
    }
};
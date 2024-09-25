class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,start=0,end=n-1;
        while(i<=end){
            if(nums[i]==0) swap(nums[i++],nums[start++]);
            else if (nums[i]==1) i++;
            else swap(nums[i],nums[end--]);
        }
    }
};
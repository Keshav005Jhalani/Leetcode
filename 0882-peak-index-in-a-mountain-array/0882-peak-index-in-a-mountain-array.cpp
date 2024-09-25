class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid=(start+end)/2;
  while(true){
    if(nums[mid]<nums[mid+1]) start=mid+1;
    else if(nums[mid]<nums[mid-1]) end=mid-1;
    else return mid;
    mid=(start+end)/2;
  }
    }
};
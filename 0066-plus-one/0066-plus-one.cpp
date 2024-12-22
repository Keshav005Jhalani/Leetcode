class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n = nums.size();
        int carry=0;
        int i=n-2;
        if(nums[n-1]==9){
            carry=1;
            nums[n-1]=0;
        }
        else{
            nums[n-1]++;
        }
        if(carry){
            while(carry){
                if(i>=nums.size()){
                    nums.insert(nums.begin(),carry);
                    return nums;
                }
                if(nums[i]==9){
                    nums[i--]=0;
                }
                else{
                    nums[i]++;
                    carry=0;
                }
            }
        }
        return nums;
    }
};
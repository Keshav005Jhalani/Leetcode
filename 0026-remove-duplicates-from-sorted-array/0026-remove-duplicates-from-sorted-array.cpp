class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=0;
        while(i<=nums.size()-1){
            if(nums[i]==nums[j]) i++;
            else nums[++j]=nums[i++]; 
        }return j+1;
    }
};
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& nums) {
        int i=0;
        int j=0;
        for(int k=0;k<=nums.size()-1;k++){
            if(nums[k]=="UP") i--;
            else if(nums[k]=="DOWN") i++;
            else if(nums[k]=="RIGHT") j++;
            else j--;
        }
        return (i * n) + j;
    }
};
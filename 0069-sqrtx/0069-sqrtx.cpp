class Solution {
public:
    int mySqrt(int x) {
        int start =0,end=x;
        long long int mid = start + (end - start) / 2;
        int ans;
        while(start <= end){
            long long int prod = mid*mid;
            if(prod==x) return mid;
            else if(prod>x) end=mid-1;
            else {
                ans=mid;
                start=mid+1;
            }
            mid=start + (end - start) / 2;
        }
        return ans;
    }
};
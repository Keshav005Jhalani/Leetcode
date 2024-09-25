class Solution {
public:
    bool isPalindrome(int x) {
        long long orignal =x;
        long long reversed =0;
        long long digit;
        while(x>0){
            digit=x%10;
            reversed=reversed*10+digit;
            x/=10;
        }
        return (reversed==orignal)?true:false;
    }
};
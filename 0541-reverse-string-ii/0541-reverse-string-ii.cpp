class Solution {
public:
    void reversePart(string &s,int start,int end){
        while(start<end){
            char temp=s[start];
            s[start++]=s[end];
            s[end--]=temp;
        }
    }
    string reverseStr(string s, int k) {
        if(k>s.size()){
            reversePart(s,0,s.size()-1);
            return s;
        }
        int low = 0;
        int high = low+k-1;
        while(high<=s.size()-1){
            reversePart(s,low,high);
            low+=2*k;
            high=low+k-1;
            if(high>s.size()-1){
                high=s.size()-1;
                reversePart(s,low,high);
                return s;
            }
        }
        return s;
    }
};
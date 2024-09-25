class Solution {
public:
    int expandAlongCenter(string s,int i,int j){
        int count=0;
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    } 
    int countSubstrings(string s) {
        int count=0;
        for(int center=0;center<=s.length()-1;center++){
            int oddCount=expandAlongCenter(s,center,center);
            int evenCount=expandAlongCenter(s,center,center+1);
            count+=(oddCount+evenCount);
        }
        return count;
    }
};
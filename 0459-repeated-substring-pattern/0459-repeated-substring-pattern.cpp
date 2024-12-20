class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                string sub = s.substr(0,i);
                string ans="";
                for(int j=1;j<=n/i;j++) ans+=sub;
                if(ans==s) return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> count(s.size());
        int i=0,j=0;
        while(j<=s.size()-1){
            s[i]=s[j];
            count[i]=1;
            if(i>0 && s[i]==s[i-1]) count[i]+=count[i-1];
            if(count[i]==k) i-=k;
            i++;j++;
        }
        return s.substr(0,i);
    }
};
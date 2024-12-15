class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> count(s.size());
        int i=0,j=0;
        while(j<=s.size()-1){
            count[i]=1;
            if(i>0 && s[i]==s[i-1]) count[i]+=count[i-1];
            if(count[i]==k) i-=k;
            i++;j++;
            s[i]=s[j];
        }
        return s.substr(0,i);
    }
};
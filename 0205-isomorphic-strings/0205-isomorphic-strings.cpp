class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> snums(256,0);
        vector<bool> tnums(256,false);
        for(int i=0;i<=s.size();i++){
            if(!snums[s[i]] && !tnums[t[i]]){
                snums[s[i]]=t[i];
                tnums[t[i]]=true;
            }
        }
        for(int i=0;i<=s.size()-1;i++){
            if(snums[s[i]]!=t[i]) return false;
        }
        return true;
    }
};
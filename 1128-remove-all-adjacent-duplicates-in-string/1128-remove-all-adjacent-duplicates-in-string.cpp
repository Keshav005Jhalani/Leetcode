class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int index=0;
        for(int i=0;i<=s.length()-1;i++){
            if(ans.empty()) ans.push_back(s[i]);
            else if(s[i]==ans.back()) ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
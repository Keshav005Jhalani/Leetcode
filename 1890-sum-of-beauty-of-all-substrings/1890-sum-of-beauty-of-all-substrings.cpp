class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<=s.size()-1;i++){
            vector<int> hash(27,0);
            for(int j=i;j<=s.size()-1;j++){
                hash[s[j]-'a']++;
                int mini=INT_MAX,maxi=INT_MIN;
                for(int k=0;k<=hash.size()-1;k++){
                    if(hash[k]){
                        mini=min(mini,hash[k]);
                        maxi=max(maxi,hash[k]);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;

    }
};
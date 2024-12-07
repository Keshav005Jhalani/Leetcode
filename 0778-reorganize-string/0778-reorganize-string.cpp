class Solution {
public:
    string reorganizeString(string s) {
        vector<int> hash(256,0);
        //hash creation
        for(int i=0;i<=s.size()-1;i++) hash[s[i]]++;
        //find max cauz we need to place max first inorder to check if arrangement possible
        int max_element=0;
        for(int i=0;i<=hash.size()-1;i++) 
        if(hash[i]>hash[max_element]){
        max_element=i;
        }
        //placing most friquient
        string ans(s.size(), ' ');
        int i=0;
        while(i<=s.size()-1 && hash[max_element]){
                ans[i]=max_element;
                hash[max_element]--;
                i+=2;
        }
        if(hash[max_element]) return "";
        hash[max_element]=0;//max element placed
        //lets place others
        for(int j=0;j<=hash.size()-1;j++){
            while(hash[j]){
                if(i>=s.size()) i=1;
                ans[i]=j;
                hash[j]--;
                i+=2;
            }
        }

        return ans;
    }
};
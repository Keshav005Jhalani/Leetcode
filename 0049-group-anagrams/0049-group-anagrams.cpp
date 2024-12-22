class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> umap;
        for(int i=0;i<=strs.size()-1;i++){
            string str = strs[i];
            sort(strs[i].begin(),strs[i].end());
            umap[strs[i]].push_back(str);
        }
        for(auto i:umap){
            ans.push_back(i.second);
        }
        return ans;
    }
};
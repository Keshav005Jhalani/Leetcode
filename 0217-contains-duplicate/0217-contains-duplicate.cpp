class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto x:nums) umap[x]++;
        for(auto x:umap) if(x.second>1) return true;
        return false;
    }
};
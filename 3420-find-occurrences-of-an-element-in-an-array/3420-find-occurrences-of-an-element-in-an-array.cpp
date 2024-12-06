class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indice;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]==x){
                indice.push_back(i);
            }
        }
        vector<int> ans(queries.size(),-1);
        for(int i=0;i<=queries.size()-1;i++){
            if(indice.size()>=queries[i]) ans[i]=indice[queries[i]-1];
        }

        return ans;
    }
};
class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& quantity,vector<int> &count,int i){
        if(i==quantity.size()) return true;
        for(int j=0;j<=count.size()-1;j++){
            if(count[j]>=quantity[i]){
                count[j]-=quantity[i];
                if(solve(nums,quantity,count,i+1)) return true;
                count[j]+=quantity[i];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        sort(quantity.rbegin(),quantity.rend());
        unordered_map<int,int> hashMap;
        for(auto i:nums){
            hashMap[i]++;
        }
        vector<int> count;
        for(auto it:hashMap){
            count.push_back(it.second);
        }
        return solve(nums,quantity,count,0);
    }
};
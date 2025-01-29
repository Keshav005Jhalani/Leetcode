class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& quantity,vector<int> &hashMap,int i){
        if(i==quantity.size()) return true;
        for(int j=0;j<=hashMap.size()-1;j++){
            if(hashMap[j]>=quantity[i]){
                hashMap[j]-=quantity[i];
                if(solve(nums,quantity,hashMap,i+1)) return true;
                hashMap[j]+=quantity[i];
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
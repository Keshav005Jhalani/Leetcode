class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        auto it = max_element(piles.begin(),piles.end());
        int end = *(it);
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            int k=mid;
            long totalHourTaken=0;
            for(int i=0;i<=piles.size()-1;i++){
                totalHourTaken+=ceil(piles[i]/(double)k);
            }
            if(totalHourTaken<=h){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }return ans;
    }
};
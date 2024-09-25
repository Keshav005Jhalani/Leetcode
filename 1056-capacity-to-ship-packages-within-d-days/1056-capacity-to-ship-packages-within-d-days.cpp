class Solution {
public:
    bool canLoad(vector<int> weights,int days,int mid){
        int loadSum=0;
        int counter=1;
        for(int i=0;i<=weights.size()-1;i++){
            if(weights[i]>mid) return false;
            if(weights[i]+loadSum>mid){
                counter++;
                if(counter>days) return false;
                loadSum=weights[i];
            }
            else loadSum+=weights[i];
        }return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=-1;
        int start=*max_element(weights.begin(), weights.end());
        int end=0;
        for(int i=0;i<=weights.size()-1;i++){
            end+=weights[i];
        }
        int mid=(start+end)>>1;
        while(start<=end){
            if(canLoad(weights,days,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
            mid=(start+end)>>1;
        }
        return ans;
    }
};
class Solution {
public:
    bool predicateFunction(vector<int>& bloomDay, int m, int k, int mid) {
        int counter = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                counter++;
                if (counter == k) {
                    bouquets++;
                    counter = 0;
                    if (bouquets == m) {
                        return true;
                    }
                }
            } else {
                counter = 0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        auto itstart = min_element(bloomDay.begin(),bloomDay.end());
        auto itend = max_element(bloomDay.begin(),bloomDay.end());
        int start = *itstart;
        int end = *itend;
        int ans=0;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if((long int)m*(long int)k>bloomDay.size()) return -1;
            

            if(predicateFunction(bloomDay,m,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};
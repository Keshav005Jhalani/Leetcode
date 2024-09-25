class Solution {
public:
    bool isPossibleSolution(vector<int> position, int m, int mid) {
        int counter=1;
        int lastPos=position[0];
        for(int i=1;i<=position.size()-1;i++){
            if(position[i]-lastPos>=mid){
                counter++;
                lastPos=position[i];
            }
            if(counter==m) return true;
        }return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start = 1;
        int end = position.back() - position.front();
        int mid = (start + end) >> 1;
        int ans=-1;
        while (start <= end) {
            if (isPossibleSolution(position, m, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid=(start+end)>>1;
        }return ans;
    }
};
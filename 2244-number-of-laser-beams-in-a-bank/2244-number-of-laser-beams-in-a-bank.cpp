class Solution {
public:
    int countInRow(string &str){
        int count=0;
        for(int i=0;i<=str.size()-1;i++){
            if(str[i]=='1'){
                count++;
            }
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        int beams=0;
        for(auto x : bank){
            devices.push_back(countInRow(x));
        }
        for(int i=0;i<=devices.size()-1;i++){
            int j=i+1;
            while(j<=devices.size()-1){
                beams+=(devices[i]*devices[j]);
                if(devices[j]==0) j++;
                else break;
            }
        }
        return beams;
    }
};
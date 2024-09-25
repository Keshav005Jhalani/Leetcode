class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP=0;
        int travelP=0;
        int lastHouseP=0;
        int pickG=0;
        int travelG=0;
        int lastHouseG=0;
        int pickM=0;
        int travelM=0;
        int lastHouseM=0;
        for(int i=0;i<=garbage.size()-1;i++){
            for(int j=0;j<=garbage[i].length()-1;j++){
                if(garbage[i][j]=='G'){
                    pickG++;
                    lastHouseG=i;
                }
                if(garbage[i][j]=='P'){
                    pickP++;
                    lastHouseP=i;
                }
                if(garbage[i][j]=='M'){
                    pickM++;
                    lastHouseM=i;
                }
            }
        }
        for(int i=0;i<=lastHouseG-1;i++) travelG+=travel[i];
        for(int i=0;i<=lastHouseM-1;i++) travelM+=travel[i];
        for(int i=0;i<=lastHouseP-1;i++) travelP+=travel[i];
        return pickP+pickM+pickG+travelP+travelG+travelM;
    }
};
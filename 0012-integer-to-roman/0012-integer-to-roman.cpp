class Solution {
public:
    string intToRoman(int num) {
        string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans="";
        int i=0;
        while(i<=values.size()-1){
            while(num>=values[i]){
                ans+=roman[i];
                num-=values[i];
            }
            i++;
        }
        return ans;
    }
};
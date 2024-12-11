class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> nums;
        nums.push_back(celsius+273.15);
        nums.push_back(celsius*1.80+32.00);
        return nums ;
    }
};
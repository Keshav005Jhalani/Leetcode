class Solution {
public:
    int convertToMin(string time) {
        int hrs = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 5));
        return hrs * 60 + min;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (auto time : timePoints) mins.push_back(convertToMin(time));
        int ans = INT_MAX;
        sort(mins.begin(), mins.end());
        for (int i = 0; i < mins.size() - 1; i++) {
            ans = min(ans, mins[i+1] - mins[i]);
        }
        int backDiff = 1440 + mins[0] - mins[mins.size() - 1];
        ans = min(ans, backDiff);
        return ans;
    }
};

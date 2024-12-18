class Solution {
public:
    int indexOf(string s) {
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < 13; i++)
            if (s == roman[i]) 
                return i;
        return -1;
    }

    int romanToInt(string s) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int ans = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && indexOf(s.substr(i, 2)) != -1) {
                ans += values[indexOf(s.substr(i, 2))];
                i++;
            } else {
                ans += values[indexOf(string(1, s[i]))];
            }
        }
        return ans;
    }
};

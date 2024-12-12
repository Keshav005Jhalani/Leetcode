class Solution {
public:
    int compress(vector<char>& s) {
        int read = 0, write = 0;
        
        while (read < s.size()) {
            char ch = s[read];
            int count = 0;
            // Count the occurrences of the current character
            while (read < s.size() && s[read] == ch) {
                count++;
                read++;
            }
            // Write the character
            s[write++] = ch;
            // Write the count (if greater than 1)
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    s[write++] = c;
                }
            }
        }
        
        return write;
    }
};


class Solution {
public:
    string reverseWords(string s) {
    reverse(s.begin(),s.end());
    int start = 0,end =0;
    while(start<=s.size()-1) {
        while(s[start]==' ' && start<=s.size()-1 ) start++;
        end=start;
        while(s[end]!=' ' && end <= s.size()-1) end++;
        reverse(s.begin()+start,s.begin()+end);
        start=end;
    }

    int i=0;
    start=0;
    while(i<=s.size()-1) {
        while(s[i]==' ' && i<=s.size()-1) i++;
        while(s[i]!=' ' && i<=s.size()-1) {
            s[start++]=s[i++];
        }
        if(i<=s.size()-1) s[start++]=' ';

    }
    if (start > 0 && s[start - 1] == ' ') start--;
    s.resize(start);
    return s;
    }
};
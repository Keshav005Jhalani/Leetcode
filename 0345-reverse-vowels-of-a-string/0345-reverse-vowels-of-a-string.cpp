class Solution {
public:
        bool isVowel(char ch){
            ch = tolower(ch);
            return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
        }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<=end){
            if(isVowel(s[start]) && isVowel(s[end])) swap(s[start++],s[end--]);
            else if(!isVowel(s[start])) start++;
            else end --;
        }
        return s;
    }
};
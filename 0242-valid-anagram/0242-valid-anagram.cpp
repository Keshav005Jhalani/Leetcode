class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTable[256]={0};
        for(int i=0;i<=s.length()-1;i++){
            freqTable[s[i]]++;
        }
        for(int i=0;i<=t.length()-1;i++){
            freqTable[t[i]]--;
        }
        for(int i=0;i<256;i++){
            if(freqTable[i]!=0)
            return false;
        }
        return true;
    }
};
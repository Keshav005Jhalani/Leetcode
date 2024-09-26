class Solution {
public:
    string normalise(string str){
        unordered_map<char,char> umap;
        char start ='a';
        for(int i=0;i<=str.length()-1;i++){
            if(umap.find(str[i])==umap.end()){
                umap[str[i]]=start;
                start++;
            }
        }
        for(int i=0;i<=str.length()-1;i++){
            str[i]=umap[str[i]];
        }
        return str;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string normalisedPattern = normalise(pattern);
        for(int i=0;i<=words.size()-1;i++){
            string str=normalise(words[i]);
            if(str.compare(normalisedPattern)==0){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    std::array<int, 256> hash(const std::string& s) {
    std::array<int, 256> hash = {0};
    for (char c : s) {
        hash[static_cast<unsigned char>(c)]++;
    }
    return hash;
}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int,256>,vector<string>> mp;
        for(auto s : strs){
            mp[hash(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
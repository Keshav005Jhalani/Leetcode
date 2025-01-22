class Solution {
public:
    unordered_map<char,string> hash = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void solve(vector<string> &ans, string digits,string output="",int i=0){
        if(digits.size()==0) return;
        if(i==digits.size()){
            ans.push_back(output);
            return;
        }
        for(auto ch:hash[digits[i]]){
            output.push_back(ch);
            solve(ans,digits,output,i+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        solve(ans,digits);
        return ans;
    }
};
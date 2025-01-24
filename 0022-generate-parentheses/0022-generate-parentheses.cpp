class Solution {
public:
    void solve(vector<string> &ans,string output,int open,int close,int n){
        if(output.size()==n*2){
            ans.push_back(output);
            return;
        }
        //open bracket if
        if(open==close||open<n){
            solve(ans,output+"(",open+1,close,n);
        }
        //close bracket if
        if(close<open){
            solve(ans,output+")",open,close+1,n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        solve(ans,"",0,0,n);
        return ans;
    }
};
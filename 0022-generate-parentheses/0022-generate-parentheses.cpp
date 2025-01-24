class Solution {
public:
    void solve(vector<string> &ans,string &output,int open,int close,int n){
        if(output.size()==n*2){
            ans.push_back(output);
            return;
        }
        //open bracket if
        if(open==close||open<n){
            output.push_back('(');
            solve(ans,output,open+1,close,n);
            output.pop_back();
        }
        //close bracket if
        if(close<open){
            output.push_back(')');
            solve(ans,output,open,close+1,n);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        solve(ans,output,0,0,n);
        return ans;
    }
};
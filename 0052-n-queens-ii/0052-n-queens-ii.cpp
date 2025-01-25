class Solution {
public:
    unordered_map<int,bool> left;
    unordered_map<int,bool> lowerDiag;
    unordered_map<int,bool> upperDiag;

    void storeSolution(vector<vector<string>> &ans,vector<string> board,int n){
        vector<string> temp;
        for(int i=0;i<=n-1;i++){
            string output="";
            for(int j=0;j<=n-1;j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    
    bool isSafe(int row,int col){
        if(left[row]||lowerDiag[row+col]||upperDiag[row-col]) return false;
        return true;
    }

    void solve(vector<string> board, vector<vector<string>> &ans,int col,int n){
        if(col>=n){
            storeSolution(ans,board,n);
            return;
        }
        for(int row=0;row<=n-1;row++){
            if(isSafe(row,col)){
                board[row][col]='Q';
                left[row]=true;
                lowerDiag[row+col]=true;
                upperDiag[row-col]=true;
                solve(board,ans,col+1,n);
                left[row]=false;
                lowerDiag[row+col]=false;
                upperDiag[row-col]=false;
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(board,ans,0,n);
        return ans.size();
    }
};
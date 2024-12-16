class Solution {
public:
    bool checkBoxes(vector<vector<char>>& board){
        for(int x:{0,3,6}){
            for(int y:{0,3,6}){
                int hash[10]={0};
                for(int i=x;i<x+3;i++){
                    for(int j=y;j<y+3;j++){
                        if(board[i][j]=='.') continue;
                        hash[board[i][j]-'0']++;
                        if(hash[board[i][j]-'0']>1) return false;
                    }
                }
            }
        }
        return true;
    }
    bool checkRows(vector<vector<char>>& board){
        for(int i=0;i<=8;i++){
            int hash[10]={0};
            for(int j=0;j<=8;j++){
                if(board[i][j]=='.') continue;
                hash[board[i][j]-'0']++;
                if(hash[board[i][j]-'0']>1) return false;
            }
        }
        return true;
    }
    bool checkCols(vector<vector<char>>& board){
        for(int i=0;i<=8;i++){
            int hash[10]={0};
            for(int j=0;j<=8;j++){
                if(board[j][i]=='.') continue;
                hash[board[j][i]-'0']++;
                if(hash[board[j][i]-'0']>1) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans1=checkBoxes(board);
        bool ans2=checkRows(board);
        bool ans3=checkCols(board);
        return ans1 & ans2 & ans3; 
    }
};
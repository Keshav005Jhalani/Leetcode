class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i,int j,int index){
        if(index==word.size()) //answer baan gaya go back
            return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) //bahar nikal gaye board kai
            return false;
        if(board[i][j]!=word[index]||board[i][j]=='.')//not correct word or already marked
            return false;

        char temp=board[i][j];
        board[i][j]='.';

        bool isFound =(
        solve(board,word,i-1,j,index+1) ||
        solve(board,word,i+1,j,index+1) ||
        solve(board,word,i,j-1,index+1) ||
        solve(board,word,i,j+1,index+1));

        board[i][j]=temp;
        return isFound;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<=board.size()-1;i++){
            for(int j=0;j<=board[0].size()-1;j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
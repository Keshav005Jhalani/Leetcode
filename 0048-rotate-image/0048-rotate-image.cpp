class Solution {
public:
    void swap(int *x,int *y){
        int temp = *x;
        *x=*y;
        *y=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        for(int i=1;i<=matrix.size()-1;i++){
            for(int j=0;j<=i-1;j++){
                swap(&matrix[i][j],&matrix[j][i]);
            }
        }
        for(int i=0;i<=matrix.size()-1;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
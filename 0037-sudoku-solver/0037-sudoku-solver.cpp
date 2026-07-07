class Solution {
public:
    bool isValid(vector<vector<char>>& board,int r,int c,int n){
        for(int i=0;i<9;i++){
        if(board[r][i]==n) return false;
        if(board[i][c]==n) return false;
        int row=3*(r/3)+i/3;
        int col=3*(c/3)+i%3;
        if(board[row][col]==n)
        return false;
        }
        return true;
    }

    bool f(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board,i,j,ch))
                        {
                            board[i][j]=ch;
                            if(f(board))
                            return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};
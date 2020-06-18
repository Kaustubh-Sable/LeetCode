class Solution {
public:
    void notSurroundedDFS(vector<vector<char>>& board, int i, int j, int &nrow, int &ncol)
    {
        board[i][j]='B';
        
        if(i+1<nrow && board[i+1][j]=='O')
            notSurroundedDFS(board, i+1, j, nrow, ncol);
        if(j+1<ncol && board[i][j+1]=='O')
            notSurroundedDFS(board, i, j+1, nrow, ncol);
        if(i-1>=0 && board[i-1][j]=='O')
            notSurroundedDFS(board, i-1, j, nrow, ncol);
        if(j-1>=0 && board[i][j-1]=='O')
            notSurroundedDFS(board, i, j-1, nrow, ncol);
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return ;
        
        int nrow = board.size(), ncol = board[0].size();
        
        for(int i=0;i<nrow;i++)
        {
            if(board[i][0]=='O')
                notSurroundedDFS(board, i, 0, nrow, ncol);
            if(board[i][ncol-1]=='O')
                notSurroundedDFS(board, i, ncol-1, nrow, ncol);
        }
        
        for(int j=1;j<ncol-1;j++)
        {
            if(board[0][j]=='O')
                notSurroundedDFS(board, 0, j, nrow, ncol);
            if(board[nrow-1][j]=='O')
                notSurroundedDFS(board, nrow-1, j, nrow, ncol);
        }
        
        for(int i=0;i<nrow;i++)
            for(int j=0;j<ncol;j++)
            {
                if(board[i][j]=='B')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
    }
};

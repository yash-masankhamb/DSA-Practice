class Solution {
public:
    bool recurSudoku(vector<vector<char>>&board)
    {
        //iterate through the matrix
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')//empty place in the board
                {
                    //check what number to place there
                    for(char c='1';c<='9';c++)
                    {
                        if(isvalid(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(recurSudoku(board)==true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]='.';//when the soduku is invalid
                            }
                        }
                    }
                    //no number is valid to be placed in the space
                    return false;
                }
            }
        }
        //when the puzzle is fukll and the no empty space lefty
        return true;


    }

    bool isvalid(vector<vector<char>>&board,int row,int col,char c)
    {
        //checking if valid horizontally,vertically and in individual matrix too
        for(int i=0;i<board.size();i++)
        {
            //for horizontal calculation
            if(board[row][i]==c)
            {
                return false;
            }
            //for vertical checking
            if(board[i][col]==c)
            {
                return false;
            }
            //for matrtix checking
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            {
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        recurSudoku(board);   
    }

};
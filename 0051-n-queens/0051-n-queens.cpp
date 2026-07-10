class Solution {
public:

    void recurQueens(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&lowerdiag,vector<int>&upperdiag,int n)
    {

        //base cas
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0)
            {
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiag[row+col]=1;
                upperdiag[n-1+col-row]=1;
                recurQueens(col+1,board,ans,leftrow,lowerdiag,upperdiag,n);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiag[row+col]=0;
                upperdiag[n-1+col-row]=0;

            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        //doing using most optimal approach
        vector<int>leftrow(n,0);
        vector<int>lowerdiag(n*2-1,0);
        vector<int>upperdiag(n*2-1,0);//sizes are important in it
        string s(n,'.');
        for(int i=0;i<n;i++)

        {
            board[i]=s;//makes .... 4 by 4 matrix
        }
        recurQueens(0,board,ans,leftrow,lowerdiag,upperdiag,n);
        return ans;


        
    }
};
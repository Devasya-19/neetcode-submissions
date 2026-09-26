class Solution {
public:
    bool isSafe(int r,int c,vector<string>&board,int n){
        int row=r;
        int col=c;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=r,col=c;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        col=c;
        // while(row>=0){
        //     if(board[row][col]=='Q')return false;
        //     row--;
        // }
        // row=r;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int c,vector<vector<string>>&ans,vector<string>&board,int n){
        if(c==n){
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(isSafe(r,c,board,n)){
                board[r][c]='Q';
                solve(c+1,ans,board,n);
                board[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans;
    }
};

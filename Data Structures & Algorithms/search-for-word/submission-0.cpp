class Solution {
public:
    bool dfs(int r,int c,int w,vector<vector<char>>&board,
            vector<vector<int>>&vis,string& word){
                if(board[r][c]!=word[w])return false;
                if(w==word.size()-1){
                    return  true;
                }
                vis[r][c]=1;
                int n=board.size(),m=board[0].size();
                int dr[4]={-1,0,1,0};
                int dc[4]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=n || nc>=m || nr<0 || nc<0)continue;
                    if(vis[nr][nc])continue;
                    if(dfs(nr,nc,w+1,board,vis,word)){
                        return true;
                    }
                }
                vis[r][c]=0;
                return false;
            }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        int len=word.size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]==word[0]){
                    if(dfs(i,j,0,board,vis,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

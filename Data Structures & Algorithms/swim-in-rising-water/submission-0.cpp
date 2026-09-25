class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            auto[time,pos]=pq.top();
            pq.pop();
            int r=pos.first;
            int c=pos.second;
            if(vis[r][c])continue;
            vis[r][c]=1;
            if(r==n-1 && c==n-1)return time;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=n || nr<0 || nc>=n || nc<0)continue;
                if(vis[nr][nc])continue;
                int newtime=max(time,grid[nr][nc]);
                pq.push({newtime,{nr,nc}});
            }
        }
        return -1;
    }
};

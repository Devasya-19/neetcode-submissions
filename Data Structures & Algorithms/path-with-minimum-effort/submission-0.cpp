class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        pq.push({0,{0,0}});
        vis[0][0]=1;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        int maxeffort=0;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int effort=it.first;
            int r=it.second.first;
            int c=it.second.second;
            vis[r][c]=1;
            maxeffort=max(maxeffort,effort);
            if(r==n-1 && c==m-1)return maxeffort;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nc<m && nr<n && !vis[nr][nc]){
                    int eff=abs(heights[r][c]-heights[nr][nc]);
                    pq.push({eff,{nr,nc}});
                }
            }
        }
        return maxeffort;
    }
};
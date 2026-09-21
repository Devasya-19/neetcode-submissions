class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>>pq;
        int ans=0;
        for(auto it:times){
            adj[it[0]].push_back({it[2],it[1]});
        }
        vector<int>vis(n+1,INT_MAX);
        vis[0]=0;
        vis[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int time=it.first;
            int node=it.second;
            if(time>vis[node]){
                continue;
            }
            for( auto i:adj[node]){
                int nextnode=i.second;
                int newtime=time+i.first;
                if(newtime<vis[nextnode]){
                    vis[nextnode]=newtime;
                    pq.push({newtime,nextnode});
                }
            }
        }
        for (int i=1;i<=n;i++){
            ans=max(ans,vis[i]);
        }
        if(ans==INT_MAX)return-1;
        return ans;
    }
};

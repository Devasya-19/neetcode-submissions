class Solution {
public:
    vector<string>ans;
    unordered_map<string,
        priority_queue<string,vector<string>,greater<string>>>mpp;
    void dfs(string airport){
        while(!mpp[airport].empty()){
            string next=mpp[airport].top();
            mpp[airport].pop();
            dfs(next);
        }
        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it :tickets){
            string from=it[0];
            string to=it[1];
            mpp[from].push(to);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

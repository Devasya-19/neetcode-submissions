class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,vector<string>>graph;
        unordered_map<string,string>mpp;
        for(auto& it : accounts){
            string name=it[0];
            string firstemail=it[1];
            for(int i=1;i<it.size();i++){
                string email=it[i];
                mpp[email]=name;
                graph[firstemail].push_back(email);
                graph[email].push_back(firstemail);
            }
        }
        unordered_set<string>visited;
        vector<vector<string>>ans;
        for(auto& [email,name]:mpp ){
            if(visited.count(email)){
                continue;
            }
            vector<string>component;
            stack<string>st;
            visited.insert(email);
            st.push(email);
            while(!st.empty()){
                string curr=st.top();
                st.pop();
                component.push_back(curr);
                for(string neighbour : graph[curr]){
                    if(!visited.count(neighbour)){
                        visited.insert(neighbour);
                        st.push(neighbour);
                    }
                }
            }
            sort(component.begin(),component.end());
            vector<string>merged;
            merged.push_back(name);
            for(string e : component){
                merged.push_back(e);
            }
            ans.push_back(merged);
        }
        return ans;
    }
};
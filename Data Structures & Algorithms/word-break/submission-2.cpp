class Solution {
public:
    bool f(int i,string&s,set<string>&words,vector<int>&dp){
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<s.size();j++){
            string sub=s.substr(i,j-i+1);
            if(words.find(sub)!=words.end()){
                if(f(j+1,s,words,dp)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        set<string>words;
        for(auto it:wordDict){
            words.insert(it);
        }
        return f(0,s,words,dp);
    }
};

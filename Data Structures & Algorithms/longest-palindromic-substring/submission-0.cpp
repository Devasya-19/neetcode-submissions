class Solution {
public:
    string f(int i,int j,string& s){
        int n=s.size();
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            string odd=f(i,i,s);
            if(odd.size()>ans.size()){
                ans=odd;
            }
            string even=f(i,i+1,s);
            if(even.size()>ans.size()){
                ans=even;
            }
        }
        return ans;
    }
};

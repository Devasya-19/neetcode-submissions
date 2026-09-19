class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size(),m=matrix[0].size();
        int t=0,l=0,d=n-1,r=m-1;
        while(t<=d && l<=r){
            for(int j=l;j<=r;j++){
                ans.push_back(matrix[t][j]);
            }
            t++;
            for(int i=t;i<=d;i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t<=d){
                for(int j=r;j>=l;j--){
                    ans.push_back(matrix[d][j]);
                }
                d--;
            }
            if(l<=r){
                for(int i=d;i>=t;i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};

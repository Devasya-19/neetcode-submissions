class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1;
        for(int i:nums){
            if(i<ans)continue;
            if(i==ans){
                ans++;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int threshold=n/3;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int l=0;
        while(l<n){
            int r=l;
            while(r<n && nums[l]==nums[r]){
                r++;
            }
            int count=r-l;
            if(count>threshold)ans.push_back(nums[l]);
            l=r;
        }
        return ans;
    }
};
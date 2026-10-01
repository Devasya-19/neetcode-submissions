class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low=0,high=0;
        for(int x:nums){
            low=max(low,(long long)x);
            high+=x;
        }
        while(low<=high){
            long long mid=low +(high-low)/2;
            int pieces=1;
            long long sum=0;
            for(int x:nums){
                if(sum+x<=mid){
                    sum+=x;
                }
                else{
                    pieces++;
                    sum=x;
                }
            }
            if(pieces<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
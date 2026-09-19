class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mpp;
        while(n!=1){
            if(mpp.find(n)!=mpp.end()){
                return false;
            }
            int sum=0;
            mpp[n]++;
            while(n>0){
                int digit=n%10;
                sum+=(digit*digit);
                n=n/10;
            }
            n=sum;
        }
        return true;
    }
};

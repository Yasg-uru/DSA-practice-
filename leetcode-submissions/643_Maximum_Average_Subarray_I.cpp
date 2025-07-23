class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start=0;
        double ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i-start+1==k){
                int temp=0;
                for(int c=start;c<=i;c++){
                    temp+=nums[c];

                }
                double tempavg=(double)temp/k;
                ans=max(ans,tempavg);
                start++;
            }
        }
        return ans;
    
    }
};
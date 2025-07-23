class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
       int i =0 , n = nums.size(), count = 0 ;
        for(int i=0;i<n;i++){
            int temp =0 ;
            while(i<n-1 and nums[i]>nums[i+1]){
                i++;
                temp++;
            }
            count+=temp;
            
        }
        return n - count ;
        
    }
};
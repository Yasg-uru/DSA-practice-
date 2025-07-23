class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0 ;
        
        int zeroCount = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCount++;
                int OnesCount = 0 ;
                for(int j=0;j<n;j++){
                    if(j==i){
                        continue;
                    }
                    if(nums[j]==1){
                        OnesCount++;
                        result= max(result , OnesCount);
                    }else{
                        OnesCount=0 ;
                    }
                }
            }
        }
        return zeroCount==0?n-1:result;
    }
};
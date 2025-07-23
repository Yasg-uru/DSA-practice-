class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         unordered_map<int , int >indexSum;
        int n = nums.size();
        int sum =0;
        for(int i =0 ;i<n;i++){
            sum+=nums[i];
            indexSum[i]= sum;
        }
        for(int  i =0 ;i<n;i++){
            int leftSum = indexSum[i-1];
            int rightSum = sum-indexSum[i];
            if(leftSum==rightSum){
                return i ;
            }
        }
        return -1;
    }
};
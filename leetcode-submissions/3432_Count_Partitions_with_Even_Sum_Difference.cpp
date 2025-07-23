class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size()-1;i++){
            int leftSum =0;
            int rightSum =0;
            for(int j=0;j<nums.size();j++){
                if(j<=i){
                    leftSum+=nums[j];
                }else{
                    rightSum+=nums[j];
                }
            }
            if((leftSum-rightSum)%2==0){
                count++;
            }
        }
        return count;
    }
};
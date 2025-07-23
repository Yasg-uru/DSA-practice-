class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int AliceScore =0 , BobScore = 0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=1 and nums[i]<10){
                AliceScore+=nums[i];
            }else{
                BobScore+= nums[i];
            }
        }
        if(AliceScore>BobScore){
            return true ;
        }
        AliceScore =0  , BobScore = 0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=10 and nums[i]<100){
                AliceScore+=nums[i];
            }else{
                BobScore+=nums[i];
            }
        }
        return AliceScore>BobScore;
    }
};
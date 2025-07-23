class Solution {
public:
    int jump(vector<int>& nums) {
        int j=0;
        int farthest=0;
        int current=0;
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,nums[i]+i);
            if(current==i){
                current=farthest;
                j++;
            }
        }
        return j;
    }
};
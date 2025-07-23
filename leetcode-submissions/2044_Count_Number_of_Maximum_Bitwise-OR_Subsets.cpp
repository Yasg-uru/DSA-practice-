class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //now i need to generate all the possible subsets of the it means if they reached to their maximum bitwise or then increament our answer 
        int maxBit=0;
        for(int ele : nums){
            maxBit=maxBit | ele;
        }
        int res=0;
        helper(res,nums,0,0,maxBit);
        return res;

    }
    void helper(int &res,vector<int>&nums,int index,int or_bit,int &maxBit){
        // base case 
        if(index>=nums.size()){
            if(maxBit==or_bit){
                res++;
            }
        return ;
        }
        helper(res,nums,index+1,or_bit,maxBit);
         helper(res,nums,index+1,or_bit | nums[index],maxBit);

    }
};
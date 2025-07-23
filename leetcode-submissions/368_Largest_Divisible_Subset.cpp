class Solution {
public:
    void solve(vector<int>&nums ,vector<int>&temp, vector<int>&result, int index , int prevEle ){
        if(index>=nums.size()){
            if(result.size()<temp.size()){
                result= temp;
            }
            return ;
        }
        // we take only and only if prev element is -1 or divisible 
        if(prevEle==-1 or nums[index]%prevEle==0){
            temp.push_back(nums[index]);
            solve(nums , temp, result, index+1, nums[index]);
            // as we passed temp variable by reference then we need to backtrack
            temp.pop_back();
        }
        solve(nums, temp , result, index+1, prevEle);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>temp ;
        sort(nums.begin(), nums.end());
        vector<int>result;
        int prev= -1 ;
        solve(nums , temp , result , 0 , prev);
        return result ;
    }
};
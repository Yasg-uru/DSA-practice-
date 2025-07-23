class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(int& n : nums){
            if(n%2){
                n= 1;
            }else{
                n=0 ;
            }
        }
        sort(nums.begin(), nums.end());
        return nums ;
    }
};
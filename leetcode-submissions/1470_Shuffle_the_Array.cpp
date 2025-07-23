class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(n*2 );
     int    i_ =0  , j_=n ;
        for(int i =0 ;i<n*2    ;i++){
            if(i%2==0){
                ans[i]= nums[i_];
                i_++;
            }else{
                ans[i]= nums[j_];
                j_++;
            }
        }
        return ans ;
    }
};
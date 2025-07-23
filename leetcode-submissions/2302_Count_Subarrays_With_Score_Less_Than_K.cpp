class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n  = nums.size();
        long  long ans =0 , i =0 , j =0, currLength =0 , currSum=0  ;
        while(j<n ){
            currSum+=nums[j];
            currLength++;
            while((currSum*currLength)>=k){
                currLength--;
                currSum-=nums[i];
                i++;
            }
            ans +=(j-i+1);
            j++;
        }
        return ans ;
    }
};
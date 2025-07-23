class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int>cnts(n , 0 );

        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k){
                cnts[i] =1;
            }
        }
        unordered_map<int , int >mp ;
        mp[0] =1;
        int sum =0 ;
        int ans =0 ;

        for(int i=0;i<n;i++){
            sum+=cnts[i];
            int rem1 = sum%modulo;
            int rem2 = (rem1-k+modulo)%modulo;
            ans+=mp[rem2];
            mp[rem1]++;

        }
        return ans ;
    }
};
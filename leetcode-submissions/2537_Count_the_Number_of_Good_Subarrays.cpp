class Solution {
public:
    bool isSame(vector<int>&nums){
        int n1 = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=n1){
                return false;
            }
        }
        return true ;
    }
    long long countGood(vector<int>& nums, int k) {
        int i  =0 , j=0 ,n = nums.size(), numPairs= 0 ;
        if(n==0){
            return 0 ;

        }
        if(isSame(nums)){
            return 1;
        }
        int ans =0 ;
        unordered_map<int , int >mp;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>1){
                numPairs++;
            }
            while(numPairs>=k){
                ans+=(n-j);
                if(mp[nums[i]]>1){
                    numPairs--;
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans ;
    }
};
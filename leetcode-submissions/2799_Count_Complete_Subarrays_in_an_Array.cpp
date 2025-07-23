class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int i =0 , j =0 , n = nums.size();
        unordered_set<int>st(nums.begin(), nums.end());
        unordered_map<int , int>mp;

        int ans  =0 , count =0 ;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]==1){
                count++;
            }
            while(count==st.size()){
                ans+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    count--;
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
    return ans ;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start=0;
        int ans=0;
        for(int end=0;end<nums.size();end++){
            int cnt=0;
            
            for(int i=start;i<=end;i++){
                if(nums[i]%2!=0){
                    cnt++;
                    if(cnt==k){
                        ans++;
                        start++;
                        break;

                    }
                }
            }
        }
        return ans;
    }
};
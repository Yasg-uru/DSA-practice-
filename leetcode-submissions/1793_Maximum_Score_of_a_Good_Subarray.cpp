class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i  =k , j= k;
        int currMin = nums[k];
        int maxAns = INT_MIN;
        while(i>0 or j<n-1){
            if(i==0 and j==n-1){
                break;
            }
            if(i==0){
                currMin = min(currMin , nums[j+1]);

                j++;
                maxAns = max(maxAns , currMin*(j-i+1));
                continue;
            }
            if(j==n-1){
                currMin = min(currMin, nums[i-1]);
                i--;
                maxAns = max(maxAns , currMin*(j-i+1));
                continue;
            }

            if(nums[i-1]>nums[j+1]){
                currMin = min(currMin, nums[i-1]);
                i--;
                maxAns = max(maxAns , currMin*(j-i+1));
            }else{
                currMin = min(currMin , nums[j+1]);
                j++;
                maxAns = max(maxAns , currMin*(j-i+1));
            }
        }
        return maxAns ;
        
    }
};
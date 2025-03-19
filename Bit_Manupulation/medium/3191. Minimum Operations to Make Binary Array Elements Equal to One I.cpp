#include<vector>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int operations = 0;
            for(int i=0;i<n-2;i++){
                if(nums[i]==1){
                    continue;
                }
                operations++;
                int j = i ;
                while(j<i+3){
                    nums[j]= nums[j]^1;
                    j++;
    
                }
    
            }
            if(nums[n-1]==0 or nums[n-2]==0){
                return -1 ;
            }
            return operations ;
        }
    };
#include<bits/stdc++.h>
using namespace std;
//brute force approach 
class Solution {
    public:
        int maximumStrongPairXor(vector<int>& nums) {
            int maxAns = INT_MIN;
    
            for(int i=0;i<nums.size();i++){
                for(int j=0;j<nums.size();j++){
                    if(abs(nums[i]- nums[j])<=min(nums[i], nums[j])){
                        int temp = nums[i] ^ nums[j];
                    maxAns = max(maxAns, temp);
                    }
                }
            }
            return maxAns;
        }
    };
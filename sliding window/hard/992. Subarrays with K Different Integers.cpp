
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        //total count of subarrays having <=k distinct integers 
    
        int solve(vector<int>&nums , int n,int k  ){
            unordered_map<int , int>mp;
            int i=0, j=0;
            int totalSubarrays = 0;
    
            while(j<n){
                mp[nums[j]]++;
                while(mp.size()>k)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
    
                }
                totalSubarrays += (j-i+1);
                j++;
            }
            return totalSubarrays;
        }
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return solve(nums  , nums.size(), k) - solve(nums , nums.size(), k-1);
        }
    };
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumSubarrayLength(vector<int>& nums, int k) {
            if(k==0) return 1;
           int n = nums.size();
           int i=0;
           int j=0;
           int minLength = INT_MAX;
    
           while(j<n){
            int currOr =0;
                for(int p=i;p<=j;p++){
                    currOr|=nums[p];
                }
                while(currOr>=k and i<n){
                    minLength = min(minLength , j-i+1);
                    
                    i++;
                    currOr= 0;
                    for(int p=i;p<=j;p++){
                    currOr|=nums[p];
                }
    
    
                }
            j++;
    
           } 
           return minLength==INT_MAX?-1:minLength;
        }
    };
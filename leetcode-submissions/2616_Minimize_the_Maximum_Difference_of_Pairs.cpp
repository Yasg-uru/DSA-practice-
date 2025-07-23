#include <vector>
#include <climits>

class Solution {
public:
    int n ;
    bool isValid (vector<int>&nums , int mid , int p){
        int countPairs =0;
        int i =0;
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid){
                countPairs++;
                i+=2;
            }else{
                i++;
            }
        }
        return countPairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        int l = 0, r= nums[n-1]-nums[0] , ans = INT_MAX;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isValid(nums , mid , p)){
                ans = mid ;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans ;

    }
};
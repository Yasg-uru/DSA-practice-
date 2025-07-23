class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>uniqueTriplets;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k = i ;k<n;k++){
                    int val = nums[i]^nums[j]^nums[k];
                    uniqueTriplets.insert(val);
                }
            }
        }
        return uniqueTriplets.size();
    }
};
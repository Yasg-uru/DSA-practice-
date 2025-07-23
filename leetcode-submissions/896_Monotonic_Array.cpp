class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool IsSorted = false;
        IsSorted=is_sorted(nums.begin(), nums.end());
        if(IsSorted) return true ;
        reverse(nums.begin(), nums.end());
        IsSorted=is_sorted(nums.begin(), nums.end());
        return IsSorted;
    }
};
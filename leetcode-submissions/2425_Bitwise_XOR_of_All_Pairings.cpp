class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result=0;
        if(nums1.size()%2){
// if the nums1 is odd then we need to use all the elements of the nums2
    for(int ele :nums2){
        result^=ele;
    }
        }
        if(nums2.size()%2){
            for(int ele : nums1){
                result^=ele;
            }
        }
        return result;
    }
};
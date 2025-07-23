class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        for(int ele:nums1){
            arr.push_back(ele);
        }
        for(int ele:nums2){
            arr.push_back(ele);

        }
        sort(arr.begin(),arr.end());
        int n=arr.size();

        return n%2!=0?arr[n/2]:(arr[n/2-1]+arr[n/2])/2.0;
    }
};
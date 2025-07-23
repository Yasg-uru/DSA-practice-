class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid-1]<arr[mid]){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        return ans;
    }
};
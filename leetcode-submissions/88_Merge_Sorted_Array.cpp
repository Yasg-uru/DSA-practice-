class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int left=0;
        int right=n;
        while(left<n && right>=0){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left++;
                right--;
            }else{
                break;
            }
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        for(int i=m;i<=m+n;i++){
            nums1[i]=nums2[i-m];
        }

        
    }
};
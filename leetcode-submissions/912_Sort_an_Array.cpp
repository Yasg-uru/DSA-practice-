class Solution {
public:
void merge(int low,int mid,int high,vector<int>&nums){
    int a=mid-low+1;
    int b=high-mid;
    vector<int>arr1(a);
    vector<int>arr2(b);
    for(int i=0;i<a;i++){
        arr1[i]=nums[low+i];
    }
    for(int j=0;j<b;j++){
        arr2[j]=nums[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<a and j<b){
        if(arr1[i]<arr2[j]){
            nums[k++]=arr1[i];
            i++;
        }else{
            nums[k++]=arr2[j];
            j++;
        }
    }
    while(i<a){
         nums[k++]=arr1[i];
            i++; 
    }
    while(j<b){
            nums[k++]=arr2[j];
            j++;
    }

}
void mergesort(int low ,int high,vector<int>&nums){
    if(low>=high){
        return ;
    }
    int mid=(low+high)/2;
    mergesort(low,mid,nums);
    mergesort(mid+1,high,nums);
    merge(low,mid,high,nums);
}
    vector<int> sortArray(vector<int>& nums) {
         mergesort(0,nums.size()-1,nums);
         return nums;
    }
};
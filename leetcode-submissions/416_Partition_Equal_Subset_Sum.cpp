class Solution {
public:

//in this question we have given constraints 
// the length of the array can upto less than or equal to 200 and nums[i] can upto 100
bool f(vector<int>&arr,int i,int k){
    //base case 
    if(k==0){
        return true;
    }
    if(i==arr.size()){
        return false;
    }
    if(arr[i]<=k){
        return f(arr,i+1,k-arr[i]) or f(arr,i+1,k);
    }else{
       return  f(arr,i+1,k);
    }
}
    bool canPartition(vector<int>& nums) {
    int s=0;
    for(int i=0;i<nums.size();i++){
        s+=nums[i];
    }
    if(s%2!=0){
        return false;
    }
    return f(nums,0,s/2);
    }
};
class Solution {
public:
int lb(vector<int>&arr,int target){
    int lo=0;
    int high=arr.size()-1;
    int ans=-1;
    while(lo<=high){
        int mid=(lo+high)/2;
        if(arr[mid]==target){
            ans=mid;
            high=mid-1;
        }
        if(target>arr[mid]){
            lo=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int ub(vector<int>&arr,int target){
    int lo=0;
    int high=arr.size()-1;
    int ans=-1;
    while(lo<=high){
        int mid=(lo+high)/2;
        if(arr[mid]==target){
            ans=mid;
           lo=mid+1;
        }
        if(target>arr[mid]){
            lo=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int l=lb(nums,target);
        int u=ub(nums,target);

        if(l!=-1){
            ans[0]=l;
            ans[1]=u;
        }
        return ans;

    }
};
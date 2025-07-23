class Solution {
public:
    bool isPossible(int mid,vector<int>&nums,int maxop){
        int totalOperations=0;

        for(int num:nums){
            int op=num/mid;
            if(num%mid==0){
                op-=1;
            }
            totalOperations+=op;
            
        }
        if(totalOperations>maxop){
            return false;
        }
        return true ;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int right =INT_MIN ;
        for(int n:nums){
            right=max(right,n);
        }
        int left=1;
        int result=0;

        while(left<=right){
            int mid=(right+left)/2;
            if(isPossible(mid,nums,maxOperations)){
result=mid;
right=mid-1;

            }else{
                left=mid+1;
            }
        }
        return result ;
    }
};
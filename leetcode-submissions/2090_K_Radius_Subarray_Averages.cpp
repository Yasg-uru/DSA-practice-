class Solution {
public:
    int getRangeSum(int l , int r, vector<int>&nums){
        int sum = 0;
        for(int i=l;i<=r;i++){
            sum+=nums[i];
        }
        return sum;
    }
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result( n , -1);
        int left = 0;
        int right = 2*k ;
       if(right>n){
        return result;
       }
        int i =k;
        int sum =  getRangeSum(left , right , nums);
        result[i] =sum/(2*k+1);
        right++;
        i++;
        while(right<n){
            int newEle = nums[right];
            int gone = nums[left];
            sum+=newEle-gone;
            result[i]= sum/(2*k+1);
            i++;
            right++;
            left++;
        }
        return result;
    }
};
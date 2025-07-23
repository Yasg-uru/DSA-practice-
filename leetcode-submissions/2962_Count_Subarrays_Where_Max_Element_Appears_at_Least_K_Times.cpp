class Solution {
public:
    int maxfinder(vector<int>array){
        int maxele=INT_MIN;
        for(int i=0;i<array.size();i++){
            maxele=max(maxele,array[i]);
        }
        return maxele;
    }
    long long countSubarrays(vector<int>& nums, int k) {
       // we are applying the approach of the sliding window 
       //we are using the two pointers start and end 
        int maxelement=maxfinder(nums);
        int count=0;
        int start=0;
        int end=0;
       while(end<nums.size()){
           k-=(nums[end++]==maxelement);
           while(k==0){
            k+=(nums[start++]==maxelement);
           }
           count+=start;

        }
        return count;
    }
};
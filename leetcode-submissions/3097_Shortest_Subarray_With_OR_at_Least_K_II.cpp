class Solution {
public:
    void update(vector<int>&bits,int number ,int val){
        for(int i=0;i<32;i++){
            if((number>>i)&1){
                bits[i]+=val;
            }
        }
    }
    int getDecimalValuesFromBits(vector<int>&bits){
        int number=0;
        for(int i=0;i<32;i++){
           if(bits[i]>0){
           number=number | (1<<i);
           }
        }
        return number ;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //to solve this question we need to use sliding window technique 
        int i=0,j=0;
        vector<int>bits(32,0);
        int n=nums.size();
        int result=INT_MAX;
        while(j<n){
            // we need to add the bits of the particular number in bits array 
            update(bits,nums[j],1);// add
            while(i<=j and getDecimalValuesFromBits(bits)>=k){
                result=min(result,j-i+1);
                update(bits,nums[i],-1);
                i++;
            }
            j++;
        }
        return result==INT_MAX?-1:result;
    }
};
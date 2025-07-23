class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // we need to find out the xor of all the elements
        int XOR=0,n=nums.size();
        vector<int>result(n);
        for(int ele:nums){
            XOR^=ele;
        }
        //after this we need to create a mask 
        int mask=((1<<maximumBit)-1);
        for(int i=0;i<n;i++){
            int k=XOR^mask;
            result[i]=k;
            XOR=(XOR^nums[n-i-1]);
        }
        return result; 
    }
};
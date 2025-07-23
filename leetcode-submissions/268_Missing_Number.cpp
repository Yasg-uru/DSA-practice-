class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expectedsum=0;
        for(int i=1;i<=n;i++){
            expectedsum+=i;
        }
        int actualsum=0;
        for(int ele:nums){
            actualsum+=ele;
        }
        int missingnum=expectedsum-actualsum;
        return missingnum;
    }
};
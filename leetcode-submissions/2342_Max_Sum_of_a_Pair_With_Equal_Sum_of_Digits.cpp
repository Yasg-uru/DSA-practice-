class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int >mp;
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            int digitSum = 0 ;
            for(char ch:s){
                int n = ch-'0';
                digitSum+=n;
            }
            if(mp.find(digitSum)!=mp.end()){
                int first = mp[digitSum];
                int second= nums[i];
                maxSum= max(maxSum, (first+second));
            }
            mp[digitSum]= nums[i];
        }
        return maxSum==INT_MIN?-1:maxSum;
    }
};
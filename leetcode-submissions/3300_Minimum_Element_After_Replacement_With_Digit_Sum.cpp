class Solution {
public:
    int minElement(vector<int>& nums) {
        int minAns  = INT_MAX ;

        for(int i =0 ;i<nums.size();i++){
            string num_string = to_string(nums[i]);
            int sum =0 ;
            for(char ch : num_string){
                sum+=(ch-'0');
            }
            minAns = min(minAns , sum);
        }
        return minAns ;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>n1;
        vector<int>n2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                n2.push_back(nums[i]);
            }else{
                n1.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<n1.size();i++){
            ans.push_back(n1[i]);
            ans.push_back(n2[i]);


        }
        return ans;
        
    }
};
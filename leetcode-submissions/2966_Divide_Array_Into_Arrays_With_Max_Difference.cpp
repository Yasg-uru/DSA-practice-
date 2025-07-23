class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums ), end(nums));
        vector<vector<int>>ans ;
        vector<int>temp;
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            temp.push_back(nums[i]);
            if(temp.size()==3){
                ans.push_back(temp);
                temp.clear();
            }

        }
        for(vector<int>&vec : ans){
            if((vec[1]-vec[0])>k or (vec[2]-vec[1])>k or (vec[2]-vec[0])>k){
                return {};
            }
        }
        return ans ;
    }
};
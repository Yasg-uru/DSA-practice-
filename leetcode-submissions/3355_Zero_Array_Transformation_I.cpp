class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diffArray(n);
        for(auto& query : queries){
            int start = query[0];
            int end = query[1];
            diffArray[start]+=1;
            if(end+1<n){
                diffArray[end+1]-=1;
            }

        }
        vector<int>result(n);
        result[0] = diffArray[0];
        for(int i =1;i<n;i++){
            result[i] = diffArray[i]+result[i-1];

        }
        for(int i =0 ;i<n;i++){
            if(result[i]<nums[i]){
                return false;
            }
        }
return true ;
    }
};
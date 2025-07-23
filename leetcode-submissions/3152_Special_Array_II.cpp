class Solution {
public:
   bool isPossible(vector<int>&nums,int start,int end){
        string prev=nums[start]%2==0?"even":"odd";

        for(int i=start+1;i<=end;i++){
            string current=nums[i]%2==0?"even":"odd";
            if(current==prev){
                return false;
            }
            prev=current;
        }
        return true ;

    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        for(auto &ele:queries){
            if(isPossible(nums,ele[0],ele[1])){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
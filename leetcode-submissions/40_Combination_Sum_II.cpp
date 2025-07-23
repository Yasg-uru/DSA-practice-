class Solution {
public:
 vector<vector<int>>ans;
void helper(vector<int>&candidates,int i,int currsum,vector<int>temp,int target){
    //base case 
    if(currsum>target){
        return ;
    }
    if(currsum==target){
        ans.push_back(temp);
        return ;
    }
    //after that we need to find for remaining 
    for(int j=i;j<candidates.size();j++){
        if(j>i and candidates[j]==candidates[j-1]){
            continue ;
        }
        temp.push_back(candidates[j]);
        helper(candidates,j+1,currsum+candidates[j],temp,target);
        temp.pop_back();
    }

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
helper(candidates,0,0,temp,target);
return ans;


    }
};
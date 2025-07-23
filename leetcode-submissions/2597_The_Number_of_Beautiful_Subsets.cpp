class Solution {
public:
int backtrack(int i,vector<int>&nums,int k,unordered_map<int,int>&mp){
    //base case 
    if(i==nums.size()){
        if(mp.size()==0){
            return 0;

        }
        return 1;
    }
    int element1=nums[i]-k;
    int element2=nums[i]+k;
    int pick=0;

    if(mp.size()==0 or (!mp.count(element1) and !mp.count(element2))){
        //include
        mp[nums[i]]++;
        //explore
        pick=backtrack(i+1,nums,k,mp);
        //backtrack 
        mp[nums[i]]--;
        if(mp[nums[i]]==0){
            mp.erase(nums[i]);

        }


    }
    int notpick=backtrack(i+1,nums,k,mp);
    return pick+notpick;
}
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        return backtrack(0,nums,k,mp);

    }
};
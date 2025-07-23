class Solution {
public:
    int n ;
    unordered_map<int , bool >mp;
    bool  solve(vector<int>&nums , long long half , int i ){
        if(i>=n){
            return 0 ;
            
        }
        int key = i+half;
        if(half==0){
            return true ;
        }
        if(half<0){
            return false;
        }
        if(mp.count(key)){
            return mp[key];
        }
        bool take = solve(nums , half-nums[i], i+1);
        bool not_take = solve(nums, half , i+1);
        return mp[key]=  take || not_take;
        
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long long half = target/2;
        long long sum =0 ;
        n = nums.size();
        for(int num : nums){
            sum+=num;
        }
        if(sum%2==1){
            return false;
        }
        return solve(nums , half ,0 );
        
    }
};
class Solution {
public:
    unordered_map<string ,long long >dp;
    int n ; 
    long long  solve(vector<int>&nums , int i , int m, int firstP, int firstIndex,  int lastP ){
        if(m==0 ){
            if(firstP==-1 or lastP==-1){
                return LLONG_MIN;
            }
            return 1LL*firstP*lastP;
            
        }
        if(i>=n or m<0){
            return LLONG_MIN; 
        }
        string key  = to_string(i)+ "|"+to_string(m)+ "|"+to_string(firstP)+ "|"+to_string(lastP)+ "|"+to_string(firstIndex);
        if(dp.count(key)){
    return dp[key];
        }
       long long take = LLONG_MIN, not_take = LLONG_MIN;
        if(firstIndex==-1){
    take = solve(nums , i+1 , m-1, nums[i],i ,  nums[i]);
    
        }else{
    take =solve(nums , i+1 , m-1 , firstP,firstIndex , nums[i]);
        }
    not_take = solve(nums , i+1 , m, firstP,firstIndex ,  lastP);
   return  dp[key]= max({take , not_take });
        
    }
    long long maximumProduct(vector<int>& nums, int m) {
        vector<int>temp ;
        n = nums.size();
      return   solve(nums , 0 , m, -1, -1, -1);

    }
};
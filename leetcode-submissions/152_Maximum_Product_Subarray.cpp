class Solution {
public:
    int n ;
    int solve(vector<int>&nums , int i , int prevProduct, map<pair<int , int >, int >mp){
        if(i>=n){
            return prevProduct;
        }
        if(mp.find({i, prevProduct})!=mp.end()){
            return mp[{i, prevProduct}];
        }
        int newProduct;
        if(prevProduct==INT_MIN){
            newProduct = nums[i];
        }else{
            newProduct=prevProduct*nums[i];
        }
        int take = solve(nums , i+1, newProduct, mp);
        int not_take = solve(nums , i+1, INT_MIN, mp);
        return mp[{i, prevProduct}]  = max({take , not_take , prevProduct});
    }
    int maxProduct(vector<int>& nums) {
        n = nums.size();
        map<pair<int , int >, int >mp;
        return solve(nums , 0 , INT_MIN, mp);
    }
};
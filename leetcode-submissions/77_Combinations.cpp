class Solution {
public:
    void solve(vector<int>&temp, vector<vector<int>>&ans ,int start , int &n , int k){
        if(k==0){
            ans.push_back(temp);
            return ;
        }
        if(start>n){
            return ;
        }
        temp.push_back(start);
        solve(temp, ans , start+1, n , k-1);
        temp.pop_back();
        solve(temp, ans , start+1,n, k);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(temp,ans  , 1, n , k);
        return ans ;
    }
};
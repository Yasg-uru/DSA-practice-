class Solution {
public:
    vector<int>parent ;
    int find(int x){
        return parent[x]=(parent[x]==x)?x:find(parent[x]);
    }
    void  Union(int x , int y){
         x = find(x);
        y = find(y);
        if(x!=y) parent[x] = y;
    }
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i ;
        }
        for(int  i=0 ;i<n-1;i++){
            if(abs(nums[i+1]- nums[i])<=maxDiff){
                Union(i , i+1 );
            }
        }
        vector<bool>ans;
        for(auto& query : queries){
            if(find(query[0])==find(query[1])){
                ans.push_back(true );
            }else{
                ans.push_back(false);
            }
        }
        return ans ;
    }
};
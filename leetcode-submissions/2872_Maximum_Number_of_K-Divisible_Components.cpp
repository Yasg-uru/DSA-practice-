class Solution {
public:
    int dfs(vector<vector<int>>&mp,vector<int>&values,int k ,int& count, int curr,int parent=-1){
        int sum=values[curr];
        for(auto& nbr:mp[curr]){
            if(nbr!=parent){
                sum+=dfs(mp,values,k,count,nbr,curr);

            }
        }
        if(sum%k==0){
            count ++;

            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int components =0;
      vector<vector<int>>mp(n);
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        //after we need to call dfs traversal
        dfs(mp,values,k,components,0);

        return components ;
    }
};
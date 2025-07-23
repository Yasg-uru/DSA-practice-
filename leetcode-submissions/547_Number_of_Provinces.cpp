class Solution {
public:
    int find(vector<int>&parent,int x){
        return parent[x]=(parent[x]==x)?x:find(parent,parent[x]);
    }
    void Union(vector<int>&parent,vector<int>&rank,int a,int b){
        a=find(parent,a);
        b=find(parent,b);
        if(a==b){
            return ;
        }
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }else{
            rank[b]++;
            parent[a]=b;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        //now finding the solution of this question by using the union find data structure in whihc we need to calculate the number of connected components only
        //in this question we are given 1 based indexing
        int n=isConnected.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 ){

                Union(parent,rank,i+1,j+1);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;

    }
};
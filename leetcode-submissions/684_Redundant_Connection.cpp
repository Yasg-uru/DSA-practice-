class Solution {
public:
        int find(vector<int>&parent,int x){
            return parent[x]=(parent[x]==x)?x:find(parent,parent[x]);
        }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //i am solvinig this question by using the union find data structure 
        //now creating the parent and rank array
        int n=edges.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;

        }
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1]; //now i extrated the two nodes and then finding the parent of this two nodes
            a=find(parent,a);
            b=find(parent,b);
            if(a==b){
                ans=edges[i];
                break;
            }
            if(rank[a]>=rank[b]){
                rank[a]++;
                parent[b]=a;

            }else{
                rank[b]++;
                parent[a]=b;
            }

        }
        return ans;
    }
};
#include <vector>
#include <algorithm>
using namespace std;
class DSU{
    public:
        vector<int>parent , rank ;
        int components ;
        DSU(int n ){
            parent.resize(n+1);

            rank.resize(n+1, 0);
            components = n;// initially we have all the components separated
            for(int i=0;i<=n;i++){
                parent[i]= i ;

            }
        }
        void Union(int u  , int v){
            u = find(u);
            v= find(v);
            if(u==v){
                return ;

            }
            if(this->rank[u]>this->rank[v]){
                this->parent[v]= u ;
            }else if (this->rank[u]<this->rank[v]){
                this->parent[u]= v;
            }else{
                this->parent[u]= v;
                this->rank[v]++;
            }
            this->components--;

        }
        int find(int x){
            return this->parent[x]=(this->parent[x]==x)?x:find(this->parent[x]);
        }
        bool isSingle(){
            return this->components==1;
        }
};
class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        auto lamda = [&](vector<int>&v1 , vector<int>&v2){
            return v1[0]>v2[0];
        };
        DSU Alice(n);
        DSU Bob(n);
        sort(edges.begin(), edges.end(), lamda);
        int NumberOfAddedEdges = 0 ;
        for(auto& edge:edges){
            int type =edge[0];
            int u = edge[1];
            int v= edge[2];
            if(type==3){

                // if type 3 then we need to check first their parents and then add the edge 
                bool isEdgeAdded = false;
                if(Alice.find(u)!=Alice.find(v)){
                    isEdgeAdded= true ;
                    Alice.Union(u , v);

                }
                if(Bob.find(u)!=Bob.find(v)){
                    isEdgeAdded= true ;
                    Bob.Union(u  , v);
                }
                if(isEdgeAdded==true){
                    NumberOfAddedEdges++;
                }

            }else if(type==1){
                if(Alice.find(u)!=Alice.find(v)){
                    
                    Alice.Union(u , v);
                    NumberOfAddedEdges++;
                }
            }else{
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u  , v);
                    NumberOfAddedEdges++;
                }
            }
        }
        if(Alice.isSingle()==true and Bob.isSingle()==true){
            return edges.size()-NumberOfAddedEdges;
        }
        return -1;
    }
};
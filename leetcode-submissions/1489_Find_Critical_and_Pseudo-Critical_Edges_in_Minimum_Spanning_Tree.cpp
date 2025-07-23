class Solution {
public:
    int N ;
    class UnionFind {
private:
    vector<int> parent, rank;
    int components; // Number of connected components

public:
    // Constructor: Initialize the DSU with 'n' elements
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Initially, all ranks are 0
        components = n; // Initially, each node is its own component
        
        // Each node is its own parent (self-loop)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

   
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        
        
        
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        components--; 
        
    }

    
   

    
    int getComponentCount() {
        return components;
    }
};
    int Krushkal(vector<vector<int>>& edges,int skip_edge, int add_edge){
        int sum = 0;
        UnionFind uf(N);

        if(add_edge!=-1){
            vector<int> edge= edges[add_edge];
            int u = edge[0];
            int v= edge[1];
            int wt = edge[2];
            sum+=wt;
            uf.Union(u, v);
        }
        for(int i=0;i<edges.size();i++){
            if(skip_edge==i){
                continue;
            }
            vector<int>edge= edges[i];
             int u = edge[0];
            int v= edge[1];
            int wt = edge[2];
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            if(parent_u!=parent_v){
                uf.Union(parent_u , parent_v);
                sum+=wt;
            }
            
        }
        if(uf.getComponentCount()>1){
            return INT_MAX;
        }
        return sum ;

    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        //we have some steps to follow to get the critical edges and pseudo edges
        // 1. add original edge 
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);//at the third index original index will be present
        }
        //sorting the edges by their weights

        auto lamda = [&](vector<int>&v1, vector<int>&v2){
            return v1[2]<v2[2];
        };
        sort(edges.begin(), edges.end(), lamda);
        int MIN_WEIGHT= Krushkal(edges, -1, -1);
        vector<int>criticalEdges, pseudoEdges;
        for(int i=0;i<edges.size();i++){
            //we need to check weather the edge is critical or pseudo
            if(Krushkal(edges, i ,-1 )>MIN_WEIGHT){
                criticalEdges.push_back(edges[i][3]);
            }else if (Krushkal(edges, -1, i)==MIN_WEIGHT){
                pseudoEdges.push_back(edges[i][3]);
            }
        }

        return {criticalEdges, pseudoEdges};
    }
};
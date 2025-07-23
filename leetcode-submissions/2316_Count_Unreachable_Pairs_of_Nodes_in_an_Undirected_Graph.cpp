class Solution {
public:
     vector<int>parent;
    vector<int>rank ;
    int find(int x){
        return parent[x]=(parent[x]==x)?x:find(parent[x]);
    }
    void Union(int x, int y ){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent){
            return ;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
            
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
           
        }else{
             parent[y_parent]=x_parent;
            rank[x_parent]++; 
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n );
        rank.resize(n , 1);
        for(int i=0;i<n;i++){
            parent[i]= i ;

        }
        for(auto& edge : edges){
            int u = edge[0];
            int v= edge[1];
            Union(u  , v);
        }
        unordered_map<int , int >mp;

        for(int i=0;i<n;i++){
            int parent = find(i);
            mp[parent]++;
        }
        int remaining = n ;
        int result = 0 ;

        for(auto& ele : mp){
            int size = ele.second ;
            result+=(size*(remaining-size));
            remaining-= size;

        }
        return result ;
    }
};
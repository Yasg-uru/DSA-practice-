class Solution {
public:
    class dsu{
        public :
        vector<int>parent , rank ;
        dsu(int n ){
            parent.resize(n);
            rank.resize(n, 1);
            for(int i =0 ;i<n;i++){
                parent[i]= i ;
            }
            
        }
        int find(int x ){
            return parent[x]==x?parent[x]:find(parent[x]);
        }
        bool Union(int a, int b){
            a = find(a);
            b = find(b);
            if(a==b){
                return false;
            }
            if(rank[a]>rank[b]){
                parent[b]= a;
            }else if(rank[a]<rank[b]){
                parent[a] = b;
            }else{
                parent[b]= a;
                rank[b]++;
            }
            return true ;
        }
    };
    int minTime(int n, vector<vector<int>>& edges, int k) {
        dsu d(n);
        int components = n;
        sort(edges.begin(), edges.end(), [](auto& a, auto& b){
            return a[2]>b[2];
        });
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            if(d.Union(u , v)){
                components--;
            }
            if(components<k){
                return time ;
            }
        }
        return 0 ;
    }
};
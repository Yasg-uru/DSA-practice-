class Solution {
public:
    class DSU{
    private : vector<int>parent;
                    vector<long long >cost_of_components;
                    int components;
    public :
        DSU(int n ){
            parent.resize(n);
            for(int i =0 ;i<n;i++){
                parent[i]= i ;

            }
            cost_of_components.assign(n , 0);
            components= n;
        }
        int find (int x){
            return parent[x]= (parent[x]==x)?x:find(parent[x]);
        }
        void unite(int u , int v , int weight){
            int parent_u = find(u);
            int parent_v = find(v);
            if(parent_u !=parent_v){
                if(parent_u<parent_v){
                    swap(parent_u , parent_v);
                }
                parent[parent_v]= parent_u;
                cost_of_components[parent_u]+cost_of_components[parent_v]+weight;
                components--;
            }
        }
        int getComponents(){
            return components;
        }
        long long getComponentCost(int x){
            return cost_of_components[x];
        }
        
    
    };
    bool canAchieve(long long maximum_allowed_cost , int n , vector<vector<int>>&edges, int k ){
        DSU dsu(n);
        for(auto&edge :edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int parent_u = dsu.find(u);
            int parent_v = dsu.find(v);
            if(parent_u==parent_v){
                continue ;
            }
            if(dsu.getComponentCost(parent_u)+dsu.getComponentCost(parent_v)+w<=maximum_allowed_cost){
                dsu.unite(u , v , w);
            }
        }
        return dsu.getComponents()<=k;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](const auto& edge_a, const auto& edge_b ){
            return edge_a[2]<edge_b[2];
        });
        int result = 0 ;
        long long l = 0 ;
        long long h = 0 ;
        for(auto& edge : edges){
            h+=edge[2];
        }
        while(l<=h){
        long long mid = l+(h-l)/2;
            if(canAchieve(mid , n , edges, k)==true){
                result = mid;
                h = mid-1;
            }else {
                l =mid+1;
            }
        }
        return result ;
    }
};
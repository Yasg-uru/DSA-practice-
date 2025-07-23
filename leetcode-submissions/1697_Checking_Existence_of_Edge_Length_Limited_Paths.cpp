class Solution {
public:
    vector<int>parent , rank;
    int find(int x ){
        return parent[x]=(parent[x]==x)?x:find(parent[x]);

    }
    void Union(int u , int v ){
        int parent_u = find(u );

        int parent_v = find(v);
        if(parent_u==parent_v){
            return ;

        }
        if(rank[parent_u]>rank[parent_v]){
          
            parent[parent_v]= parent_u;


        }else if(rank[parent_u]<rank[parent_v]){
           
            parent[parent_u]= parent_v;
        }else {
            rank[parent_u]++;
            parent[parent_v]= parent_u;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
   //this question can be solved by making the adjacency matrix and then start traversing from the ith query src to dest but it it inefficient it takes too much time also it could give time limit exceeded 

        parent.resize(n );
        rank.resize(n , 0 );
        for(int i=0;i<n;i++){
            parent[i]= i ;
        }
        int m = queries.size();
        for(int i=0;i<m;i++){
            queries[i].push_back(i); // inserting the original index to make valid answer 

        }
        auto lamda= [&](vector<int>&v1, vector<int>&v2){
            return v1[2]<v2[2];

        };
        sort(begin(edgeList), end(edgeList), lamda);
        sort(begin(queries), end(queries), lamda);
        int j =0 ;
        vector<bool>ans(m );
        for(int i=0;i<m;i++){
            int u = queries[i][0];

            int v = queries[i][1];
            int limit = queries[i][2];
            int index = queries[i][3];
            while(j<edgeList.size() and edgeList[j][2]<limit){
                Union(edgeList[j][0], edgeList[j][1]); // building graph as per requirements 
                j++;
            }
            if(find(u)==find(v)){
                ans[index]= true;
            }else{
                ans[index]= false;
            }

        }
        return ans ;

    }
};
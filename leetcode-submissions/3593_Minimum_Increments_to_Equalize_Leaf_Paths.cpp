class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        unordered_map<int , vector<int>>adj;
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            
        }
        set<int>paths ;
        queue<pair<int, int >>q;
        q.push({0,cost[0]});
        while(not q.empty()){
            auto [currNode , currCost]= q.front();
            q.pop();
            if(adj[currNode].size()==0){
                paths.insert(currCost);
            }

            for(int &nbr:adj[currNode]){
                q.push({nbr , currCost+cost[nbr]});
            }
        }
        int max_path = *max_element(paths.begin(), paths.end());
        int count =0 ;
        for(int path : paths){
            if(max_path>path){
                count++;
            }
        }
        return count;
        
    }
};
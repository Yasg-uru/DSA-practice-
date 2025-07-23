class Solution {
public:
    double BFS(string src , string dest, unordered_map<string , vector<pair<string, double>>>&adj){
        queue<pair<string , double>>q;
        unordered_set<string>visited;
        visited.insert(src);
        q.push({src,1.0});
        while(not q.empty()){
            auto p = q.front();
            q.pop();
            string currNode = p.first;
            double currAns = p.second;
            if(currNode==dest){
                return currAns ;

            }
            for(auto& nbr : adj[currNode]){
               if(visited.find(nbr.first)==visited.end()){
                 q.push({nbr.first , currAns*nbr.second});
                 visited.insert(nbr.first);
               }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string , vector<pair<string, double>>>adj;
       int n = equations.size();
       for(int i=0;i<n;i++){
        string u = equations[i][0];
        string v = equations[i][1];
        double wt = values[i];
        adj[u].push_back({v, wt});
        adj[v].push_back({u , (double)1/wt});

       }
       vector<double>ans;
       

       for(auto& query : queries){
        string src = query[0] ;
        string dest = query[1];
        if(adj.find(src)==adj.end()){
            ans.push_back(-1.0);
            continue;
        }
        double result = BFS(src, dest, adj);
        ans.push_back(result);

       }  
       return ans ;
    }
};
class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int, int>bobMap;
    int maxIncome = 0;
    bool DFSBob(int curr , vector<bool>&visited, int time ){
        visited[curr]= true ;
        bobMap[curr]= time ;
        if(curr==0) {
            return true ;
        }
        for(auto& nbr:adj[curr]){
            if(not visited[nbr]){
                if(DFSBob(nbr, visited, time+1)){
                    return true ;
                }
            }
        }
        bobMap.erase(curr);
        return false;
    }
    void DFSAlice(int curr , int time , vector<bool>&visited , int income ,vector<int>& amount ){
        visited[curr]= true;
        if(bobMap.find(curr)==bobMap.end() or time<bobMap[curr]){
            // alice can collect full income of the node
            income+=amount[curr];
        }else if(bobMap[curr]==time){
            income+=(amount[curr]/2);
        }
        if(adj[curr].size()==1 and curr!=0){
            maxIncome = max(maxIncome, income);
        }
        for(auto& nbr :adj[curr]){
            if(not visited[nbr]){
                DFSAlice(nbr, time+1, visited, income, amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); // it 0 to n-1
        maxIncome = INT_MIN;
        for(vector<int>&edge :edges){
            int u = edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n, false);
        int time = 0 ;
        DFSBob(bob , visited, time);
        visited.assign(n , false);
        int income = 0 ;
        DFSAlice(0 , 0 , visited,income, amount);
        return maxIncome;

    }
};
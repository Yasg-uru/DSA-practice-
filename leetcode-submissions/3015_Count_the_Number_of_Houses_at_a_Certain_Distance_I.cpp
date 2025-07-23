class Solution {
public:
    int bfs(int sourceNode , unordered_map<int , vector<int >>&adj , int distance, unordered_set<int>&visited){
        queue<pair<int  ,int >>q;
        int count =0 ;
        visited.insert(sourceNode);
        q.push({sourceNode,  0 });
        while(not q.empty()){
            auto [currNode , dist]= q.front();
            if(dist==distance){
                count++;
            }
            q.pop();
            for(int& nbrNode:adj[currNode]){
                if(not visited.count(nbrNode)){
                    q.push({nbrNode ,dist+1});
                    visited.insert(nbrNode);
                }
            }
        }
        return count ;
    }
    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int , vector<int >>adj;
        adj[x].push_back(y);
        adj[y].push_back(x);
        for(int i=1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);

        }
        vector<int>ans;
        unordered_set<int>visited;
        for(int k=1;k<=n;k++){
            int count =0 ;
            for(int i=1;i<=n;i++){
                visited.clear();
                count+=bfs(i ,adj , k, visited);

            }
            ans.push_back(count);
        }
        return ans ;
    }
};
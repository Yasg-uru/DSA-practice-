class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue<int>q;
        unordered_map<int , vector<int>>adj ;
        vector<int>indegree(n , 0 );
        for(auto& relation : relations){
            int u = relation[0];
            int v = relation[1];
            adj[u-1].push_back(v-1); //making 0 based graph 
            indegree[v-1]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int totalMinCost = 0 ;
        while(not q.empty()){
            int size = q.size();
            int maxLevelCost= 0 ;
            while(size--){
                int currNode = q.front();
                // finding the time of the currentNode 
                maxLevelCost= max(time[currNode], maxLevelCost);
                q.pop();
                for(auto& nbr : adj[currNode]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0){
                        q.push(nbr);

                    }
                }

            }
            totalMinCost+=maxLevelCost;
        }
        return totalMinCost ;
        
    }
};
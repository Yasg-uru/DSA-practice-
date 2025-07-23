class Solution {
public:
    typedef pair<int,int> P ;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<P>q;
        set<P>visited;
        for(int i=0;i<n;i++){
            int mask = (1<<i);
            q.push({i , mask});
            visited.insert({ i , mask});
        }
        int destinationMask = pow(2,n)-1;
        int path = 0 ;
        while(not q.empty()){
             path++;
            int size = q.size();
            while(size--){
                int currNode = q.front().first;
            int currMask = q.front().second ;
            q.pop();
            for(int& nbr : graph[currNode]){
                int nextMask = currMask | (1<<nbr);
                if(nextMask ==destinationMask){
                    return path ;
                }
                if(visited.find({nbr , nextMask})==visited.end()){
                    q.push({nbr, nextMask});
                    visited.insert({nbr, nextMask});
                }
            }
            }
           
        }
        return -1 ;

    }
};
class Solution {
public:
    void DFSForCalculatingDistanceFromSourcetoDestination(unordered_map<int, vector<int>>&adj , vector<int>&dist, int currSteps, int currNode, vector<int>&visited){
        visited[currNode]= true;
        // updating distance array 
        dist[currNode]= currSteps;
        for(auto& nbr: adj[currNode]){
          if(not visited[nbr]){
              DFSForCalculatingDistanceFromSourcetoDestination(adj , dist, currSteps+1, nbr, visited);
          }

        }

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int , vector<int>>adj ;
        int n = edges.size();
        for(int i=0;i<n;i++){
            // i-> edge[i]
            if(edges[i]==-1){
                continue;
            }
            adj[i].push_back(edges[i]);

        }
        vector<int>distFromNode1(n , INT_MAX);

        vector<int>distFromNode2( n, INT_MAX);
        vector<int>visited1(n , false);
        vector<int>visited2(n , false);

        DFSForCalculatingDistanceFromSourcetoDestination(adj , distFromNode1, 0 , node1, visited1);
        DFSForCalculatingDistanceFromSourcetoDestination(adj , distFromNode2, 0 , node2, visited2);
        int minDistNode = -1 ;
        int minDistTillNow= INT_MAX ;
        for(int i=0;i<n;i++){
            int maxD = max(distFromNode1[i], distFromNode2[i]);
            if(minDistTillNow>maxD){
                minDistTillNow= maxD;
                minDistNode = i;

            }
        }
        return minDistNode;
    }   
};
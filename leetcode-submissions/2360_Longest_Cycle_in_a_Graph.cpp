class Solution {
public:
    int result = -1 ;
    void dfs(unordered_map<int , vector<int>>&adj, int currNode , vector<bool>&visited, vector<int>&inRecursion, vector<int>&count){
        inRecursion[currNode]= true ;
        visited[currNode]= true ;
        for(auto& nbr : adj[currNode])
        {
            if(not visited[nbr]){
                // we need to update the count states 
                count[nbr] = count[currNode]+1; // one step we are moving 
                dfs(adj , nbr , visited, inRecursion, count);

            }else if(inRecursion[nbr]==true){
                int cycleLength = count[currNode]- count[nbr]+1;
                result = max(result , cycleLength);
            }
        }
        inRecursion[currNode]=false;

    }
    int longestCycle(vector<int>& edges) {
       int  n = edges.size();
       vector<int>inRecursion(n , false);
       vector<bool>visited(n , false);
       vector<int>count(n , 0); // it denotes number of steps to reach that node node -> steps 0->3 = 1 count

       unordered_map<int , vector<int>>adj ;
       for(int i=0;i<n ;i++){
        if(edges[i]==-1){
            continue;

        }
        int  u = i ;
        int v= edges[i];
        adj[u].push_back(v);

       } 
       for(int i=0;i<n;i++){
        if(not visited[i]){
            dfs(adj , i , visited, inRecursion, count);

        }
       }
       return result ;
    }
};
class Solution {
private:
    int BFS(int start ,vector<bool>&visited, unordered_map<int,vector<int>>&adj){
        int maxDistance =0;
        queue<pair<int,int>>q;
        q.push({start,0});
        visited[start]=true;
        while(not q.empty()){
            auto [currNode,dist]=q.front();
            q.pop();
            for(auto &nbr:adj[currNode]){
                if(not visited[nbr]){
                    q.push({nbr,dist+1});
                    visited[nbr]=true;
                    maxDistance=max(maxDistance,dist+1);

                }
            }
        }
        return maxDistance ;

    }
public:
    int maximumInvitations(vector<int>& favorite) {
        unordered_map<int,vector<int>>adj;
        int n =favorite.size();
        for(int i=0;i<n;i++){
            int u=i;
            int v= favorite[i];
            adj[v].push_back(u);// we are reversing the graph because it help us to traverse easily 

        }
        int longestCycleEmplyCount=0;
        int happyCoupEmplyCount=0;
        vector<int>visited(n,false);
        // we need to start traversal and then count the current node counts then keep track if we fount the cycle or not if not found then keep moving forwards until all the nodes should not be traveresed
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;//this map is responsible to keep track of the node their previous visited counts 
            int currNode =i;
            int currNodeCount =0;//initially the node is the first node
            while(not visited[currNode]){
                mp[currNode]=currNodeCount;
                visited[currNode]=true;
                int nextNode =favorite[currNode];// favorite of the currnode is their next couple
                currNodeCount+=1;
                // we need to check wether the next node is already visited then we found the cycle in the graph then we need to do some operations 
                if(visited[nextNode]){
                    int cycleLength =currNodeCount-mp[nextNode];
                    longestCycleEmplyCount=max(longestCycleEmplyCount,cycleLength);
                    if(cycleLength==2){
                        vector<bool>visitedNodes(n,false);
                        visitedNodes[currNode]=true;
                        visitedNodes[nextNode]=true;
                        happyCoupEmplyCount+=(2+BFS(currNode,visitedNodes,adj)+BFS(nextNode,visitedNodes,adj));
                    }
                    break;
                }
                currNode=nextNode ;

            }
        }
return max(longestCycleEmplyCount,happyCoupEmplyCount);
    }
};
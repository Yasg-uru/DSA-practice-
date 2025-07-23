class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int , vector<int>>adj;
        // it stores stop to routes
         for(int route=0 ;route<routes.size();route++){
            for(int& stop : routes[route]){
                adj[stop].push_back(route);
            }
         }
         queue<int>q; // it store the buses that starts from the source stop 
         unordered_set<int>visited;

         for(int& route : adj[source]){
            q.push(route);
            visited.insert(route);
         }
         int stops = 1;
         while(not q.empty()){
            int size = q.size() ;
            while(size--){
                int currRoute = q.front();
                q.pop();
                // from this route we can go to next stops 
                for(int& stop : routes[currRoute]){
                    if(stop==target){
                        return stops;
                    }
                    // if we cant reach at the stops then we need to take others buses as well 
                    for(int& nextRoute: adj[stop]){
                        if(not visited.count(nextRoute)){
                            visited.insert(nextRoute);
                            q.push(nextRoute);

                        }
                    }
                }
            }
            stops++;

         }
         return -1 ;
    }
};
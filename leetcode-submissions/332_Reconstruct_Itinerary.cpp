class Solution {
public:
    vector<string>result;
    unordered_map<string , vector<string>>adj;
    int numberOfTickets ;
    bool DFS(string fromAirport, vector<string>&path){
        path.push_back(fromAirport);
        //check if we covered all the stations 
        if(path.size()==numberOfTickets+1){
            result = path;
            return true ; // we got first smallest path so return from here 

        }
        vector<string>&neighbors = adj[fromAirport];// from here how many tickets we can cover 
        for(int i=0;i<neighbors.size();i++){
            string toAirPort = neighbors[i]; //first smallest 
            neighbors.erase(neighbors.begin()+i);
            if(DFS(toAirPort, path)==true){
                return true ;
            }
        }
        path.pop_back();//removing the path 
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // we need to create a adj list of string -> string, 
        numberOfTickets= tickets.size();

        for(auto& ticket : tickets){

            string u = ticket[0];
            string v= ticket[1];
            adj[u].push_back(v);
            
        }
        for(auto& ele : adj){
            sort(ele.second.begin(), ele.second.end());
        }
        vector<string>path;
        DFS("JFK", path);
        return result ;

        
    }
};
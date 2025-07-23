class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // we have already given a adjacency list 
        int n=rooms.size();
        vector<int>visited(n , false);
        queue<int>q;
        q.push(0);
        visited[0]= true ;
        while(not q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto& nbr : rooms[currNode]){
                if(not visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true ;

                }
            }
        }
        for(int i=0;i<n ;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true ;
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto edge:edges){
            if(edge[0]==source and edge[1]==destination){
                return true;
            }else if(edge[1]==source and edge[0]==destination){
                return true;
            }
        }
        return  false;
    }
};
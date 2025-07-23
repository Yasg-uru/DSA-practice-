class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //now we are writing the solution of this code by using the queue data structure that can might able to help intraversing level wise order
        int n=graph.size();
        vector<int>color(n,-1);
        //initialized by -1
        queue<int>q;
        q.push(0);
        color[0]=0;
        while(not q.empty()){
            int node=q.front();
            q.pop();
            for(auto neighbour:graph[node]){
                if(color[neighbour]==-1){
                    color[neighbour]=1-color[node];
                    q.push(neighbour);

                }else if(color[neighbour]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};
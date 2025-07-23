class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //now we need to find out the endegree of every nodes and then check if any node exist their indegree will be equal to the total number of edges

        int n=edges.size();
        vector<int>indegree(n+2,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            if(indegree[edges[i][0]]==n){
                return edges[i][0];
            }
            else if(indegree[edges[i][1]]==n){
                return edges[i][1];
            }
        }
    return -1;
    }

};
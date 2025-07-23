class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // we have a simple approach to solve this question we need to find the indegree of the node with zero that is the part od the our answer
        vector<int>indegree(n,0);
         vector<int>ans;
        for(int i=0;i<edges.size();i++){
             
                 indegree[edges[i][1]]++;
            
            
        }
             for(int i=0;i<indegree.size();i++){
                if(indegree[i]==0){
                    ans.push_back(i);
                }
        }
       
        return ans;
    }
};
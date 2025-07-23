class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //now solving this question by using graph topological sort algorithm

        //creating the graph for this input
        vector<list<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>ans;
        for(auto ele:prerequisites){
            graph[ele[1]].push_back(ele[0]);
            indegree[ele[0]]++;



        }

        //now creating the queue
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                //inserting the vertices 
            }
        }
        while(not q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour:graph[node]){

            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
            }
            
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return  {};
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //now we have a simple approach to solve this question : Topological sort
        
vector<vector<int>>adj(numCourses);
vector<int>indegree(numCourses,0);
vector<int>ans;
//now inserting all the adjacents on the adjacent array
for(auto x:prerequisites){
    adj[x[1]].push_back(x[0]);
    indegree[x[0]]++;
}
queue<int>q;
for(int i=0;i<indegree.size();i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
while(not q.empty()){
    int node=q.front();
    ans.push_back(node);
    q.pop();
    for(int ele:adj[node]){
        indegree[ele]--;
        if(indegree[ele]==0){
            q.push(ele);
        }
    }
}

 return ans.size()==numCourses;
        
    }
};
class Solution {
public:
pair<int,int> BFS(unordered_map<int,vector<int>>adj,int src){
    queue<int>q;
int distance =0;
int farthestNode=src;

    q.push(src);
    set<int>visited;
    while(not q.empty()){
int size=q.size();
while(size--){
    int currNode =q.front();
    farthestNode=currNode ;
    q.pop();
    for(auto &nbr:adj[currNode]){
        if(!visited.count(nbr)){
            q.push(nbr);
            visited.insert(nbr);
        }
    }

}
if(not q.empty()){
    distance ++;
}

    }
    return {farthestNode ,distance};
}
 unordered_map<int,vector<int>> buildAdj(vector<vector<int>>&edges){
  unordered_map<int,vector<int>>adj;
    for(auto &edge:edges){
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
    }
    return adj;
 }


 int findDiameter(unordered_map<int,vector<int>>adj){
    auto [farthestNode,dist]=BFS(adj,0);
    auto [otherEndNode,diameter]=BFS(adj,farthestNode);
    return diameter;
 }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
     // we need to find the diameter and then  comparing them which one is the largest and then return the answer
     unordered_map<int,vector<int>>adj1=buildAdj(edges1);   
     unordered_map<int,vector<int>>adj2=buildAdj(edges1);   
     int d1 =findDiameter(adj1);
     int d2=findDiameter(adj2);
     int combinedDiameter =(d1+1)/2+(d2+1)/2+1;//extra edge 
     return max({d1,d2,combinedDiameter});
    }
};
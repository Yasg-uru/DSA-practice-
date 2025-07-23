class Solution {
public:
    int BFS(int startNode , unordered_map<int,vector<int>>&adj){
        queue<int>q;
        int nodes =0;
        unordered_set<int>visited;
        q.push(startNode);
        visited.insert(startNode);
        while(not q.empty()){
            int currNode = q.front();
            q.pop();
            nodes++;
            for(int nbr:adj[currNode]){
                if(not visited.count(nbr)){
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }
        return nodes ;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>child_to_parent ;
        for(int i=0;i<n;i++){
            int root =i;
            int leftC= leftChild[i];
            int rightC= rightChild[i];
            if(leftC!=-1){
                if(child_to_parent.find(leftC)!=child_to_parent.end()){
                    return false;//already this left child is asigned 

                }
                adj[i].push_back(leftC);
                child_to_parent[leftC]=i;
            }
            if(rightC!=-1){
                if(child_to_parent.find(rightC)!=child_to_parent.end()){
                    return false;
                }
                child_to_parent[rightC]=i;
                adj[i].push_back(rightC);
            }

        }
        //finding parent ;
        int parent =-1;
        for(int i=0;i<n;i++){
            if(child_to_parent.find(i)==child_to_parent.end()){
                if(parent!=-1){
                    return false; // two parents exists 
                }
                parent = i ;
            }
        }
        return BFS(parent,adj)==n;
    }
};
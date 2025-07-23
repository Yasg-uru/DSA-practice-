class Solution {
public:
void dfs(vector<vector<int>>&graph,vector<int>&visited,int i){
    visited[i]=1;
    for(auto &stones:graph[i]){
        //all the nieghbours meand connected components 
        if(!visited[stones]){
dfs(graph,visited,stones);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int a,b,c,d;
        int n=stones.size();

        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            a=stones[i][0];
            b=stones[i][1];
            for(int j=i+1;j<n;j++){
c=stones[j][0];
d=stones[j][1];
if(a==c or b==d){
    //then stones is lying on same direction
    graph[i].push_back(j);
    graph[j].push_back(i);
}
            }
        }
        int count=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                //this is a different component
                dfs(graph,visited,i);
                count++;

            }
        }
return n-count ;

    }
};
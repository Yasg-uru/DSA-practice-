class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int>indegree(n , 0);
        unordered_map<int , vector<int>>adj ;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        vector<vector<int>>colorCountAtCurrentNode(n , vector<int>(26, 0));
        int processedNodes = 0 ;
        int answer = 0 ;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0){
                q.push(i);
                colorCountAtCurrentNode[i][colors[i]-'a'] = 1; 
            }
        }
        while(not q.empty()){
            int u = q.front();
            q.pop();
            processedNodes++;
            answer = max(answer ,colorCountAtCurrentNode[u][colors[u]-'a'] );
            for(auto& v : adj[u]){
                for(int i=0;i<26;i++){ //vising on every color and updating matched color count
                    colorCountAtCurrentNode[v][i] = max(colorCountAtCurrentNode[v][i],colorCountAtCurrentNode[u][i]+(colors[v]-'a'==i));
                }
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);

                }
            }

        }
        if(processedNodes<n){
            return -1 ;

        }
        return answer;
        
        
    }
};
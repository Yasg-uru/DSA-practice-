class Solution {
public:
    char DFS(unordered_map<char, vector<char>>&adj , char curr, vector<bool>&visited){
        visited[curr-'a']= true;
        char minChar = curr;
        for(char& nbr : adj[curr]){
            if(not visited[nbr-'a']){
                minChar = min(minChar, DFS(adj , nbr, visited));

            }
        }
        return minChar ;

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char , vector<char>>adj ;
        int n = s1.size();
        int m = baseStr.size();
        for(int i=0;i<n;i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        
        for(int i=0;i<m ;i++){
            vector<bool>visited(26, false);
            baseStr[i]= DFS(adj , baseStr[i],visited);

        }
        return baseStr;

    }
};
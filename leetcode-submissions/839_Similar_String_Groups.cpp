class Solution {
public:
    void DFS(unordered_map<int, vector<int>>&adj , int currNode , vector<bool>&visited){
visited[currNode]= true;
        for(auto& nbr : adj[currNode]){
            if(not visited[nbr]){
                DFS(adj , nbr , visited);
            }
        }
    }
    bool isSimilar(string s1 , string s2){
        int diff = 0;

        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diff++;
            }
        }
        return diff==2 or diff==0;
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int , vector<int>>adj ;
        int n = strs.size();
        vector<bool>visited(n , false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n ;j++){
                if(isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int components = 0 ;

        for(int i=0;i<n;i++){
            if(not visited[i]){
                components++;
                DFS(adj , i , visited);

            }
        }
        return components ;

    }
};
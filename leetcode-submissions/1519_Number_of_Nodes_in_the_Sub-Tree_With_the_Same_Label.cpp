class Solution {
public:
    void DFS(int currNode, unordered_map<int , vector<int>>&adj , string labels ,vector<int>&count,vector<int>&result,  int parent ){
        char currChar = labels[currNode];
        int count_of_current_char_before_visiting_current_node = count[currChar-'a'];
        count[currChar-'a']++;
        for(auto& nbr : adj[currNode]){
            if(nbr==parent){
                continue ;

            }
            
            DFS(nbr , adj , labels,count ,result ,  currNode );

        }
        int count_of_current_char_after_visiting_current_node_and_their_childs=count[currChar-'a'];
        result[currNode]= count_of_current_char_after_visiting_current_node_and_their_childs-count_of_current_char_before_visiting_current_node;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int , vector<int >>adj ;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>count(26, 0 );
        vector<int>result(n , 0);
        DFS(0, adj , labels , count ,result ,  -1);
        return result ;

    }
};
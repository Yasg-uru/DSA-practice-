class Solution {
public:
    int result ;
    int DFS(unordered_map<int , vector<int>>&adj , string& s , int currNode , int parent){
        int largest= 0 ;
        int second_largest = 0;

        for(auto& nbr : adj[currNode]){
            if(nbr==parent){
                continue;

            }
            if(s[nbr]==s[currNode]){
                continue;
            }
            int child_longest_path = DFS( adj , s, nbr , currNode);
            if(child_longest_path>largest){
                second_largest = largest ;

                largest = child_longest_path;
            }else if(child_longest_path>second_largest){
                second_largest= child_longest_path;
            }
            
        }
            int only_root = 1;
            int niche_se_answer_mil_gaya = 1+largest + second_largest;
            int koi_ek_achha_sa = max(largest , second_largest)+1;
            result = max({result , koi_ek_achha_sa,niche_se_answer_mil_gaya, only_root });
            return max(koi_ek_achha_sa,only_root );
    }
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int , vector<int>>adj;
        int n = parent.size();
        for(int i=1;i<n;i++){
            int u =i ;
            int v= parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        DFS(adj , s, 0 , -1);
        return result ;
    }
};
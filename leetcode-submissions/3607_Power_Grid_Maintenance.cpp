class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int , vector<int>>adj;
        for(vector<int>e : connections){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>cId(c+1, 0);
        vector<int>visited(c+1, false);
        int Id = 1;
        for(int i =1;i<=c;i++){
            if(not visited[i]){
                queue<int>q;
                q.push(i);
                visited[i] = true ;
                cId[i] = Id;
                while(not q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(int nbr : adj[curr]){
                        if(not visited[nbr]){
                            visited[nbr] = true;
                            cId[nbr] = Id;
                            q.push(nbr);
                        }
                    }
                }
                Id++;
            }
        }
        unordered_map<int , set<int>>O;
        vector<bool>I(c+1, true);
        for(int i =1;i<=c;i++){
            O[cId[i]].insert(i);
        }
        vector<int>ans;
        for(auto& ele:queries){
            int m = ele[0];
            int n  = ele[1];
            int k = cId[n];
            if(m==1){
                if(I[n]){
                    ans.push_back(n);
                }else{
                    if(O[k].empty()){
                        ans.push_back(-1);
                    }else{
                        ans.push_back(*O[k].begin());
                    }
                }
            }else{
                if(I[n]){
                    I[n]= false;
                    O[k].erase(n);
                }
            }
        }
        return ans ;
    }
};
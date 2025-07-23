class Solution {
public:
    class UnionFind {
private:
    vector<int> parent, rank;
    int components; // Number of connected components

public:
    // Constructor: Initialize the DSU with 'n' elements
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Initially, all ranks are 0
        components = n; // Initially, each node is its own component
        
        // Each node is its own parent (self-loop)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by Rank: Merge two sets
    bool Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false; // Already in the same set
        
        // Attach smaller tree under larger tree
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        components--; // Reduce component count
        return true;
    }

    // Check if two nodes belong to the same component
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    // Get the number of connected components
    int getComponentCount() {
        return components;
    }
};

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        vector<vector<string>>ans ;
        unordered_map<string , int >mailToNode ;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mailToNode.find(accounts[i][j])==mailToNode.end()){
                    mailToNode[accounts[i][j]]= i;
                }else{
                    uf.Union(i, mailToNode[accounts[i][j]]);

                }
            }
        }
        // we have email to node number and also their parents as well 
        vector<vector<string>>jointAccounts(n);
        for(auto& ele : mailToNode){
            string  mail = ele.first;
            int node = ele.second ;
            int parentOfNode = uf.find(node);
            jointAccounts[parentOfNode].push_back(mail);
        }
        // we have joint accounts means 0->j1 , j2 , j3 , j4 
        for(int i=0;i<n;i++){
            vector<string>mergedMails = jointAccounts[i];
            if(mergedMails.empty()){
                continue;
            }
            vector<string>temp;
            sort(mergedMails.begin(), mergedMails.end());
            temp.push_back(accounts[i][0]);
            for(string& mail : mergedMails){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        
        return ans ;
    }
};
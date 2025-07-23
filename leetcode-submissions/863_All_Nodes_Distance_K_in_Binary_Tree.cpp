/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createGraph(unordered_map<int,vector<int>>&adj, TreeNode* root, int parent ){
        if(not root) return ;
        if(parent!=-1){
            adj[root->val].push_back(parent);
        }
        if(root->left){
            adj[root->val].push_back(root->left->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
        }
        parent = root->val;
        createGraph(adj,root->left,parent);
        createGraph(adj,root->right,parent);
        

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>adj;
        unordered_set<int>visited;
        vector<int>ans ;
        int parent =-1;
        createGraph(adj,root,parent);
        queue<pair<int,int>>q;
        q.push({target->val,0});
        visited.insert(target->val);
        while(not q.empty()){
            auto [currNode, currDistance]=q.front();
            if(currDistance==k){
                ans.push_back(currNode);
            }
            q.pop();
            for(auto& nbr : adj[currNode]){
                if(not visited.count(nbr)){
                    q.push({nbr, currDistance+1});
                    visited.insert(nbr);

                }
            }
        }
        return ans ;
    }
};
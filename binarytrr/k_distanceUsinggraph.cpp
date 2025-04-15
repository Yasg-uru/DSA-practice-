/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // USING GRAPH CONCEPT
class Solution {
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*,vector<TreeNode*>> mp;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    mp[node].push_back(node->left);
                    mp[node->left].push_back(node);
                    q.push(node->left);
                }
                if(node->right){
                    mp[node].push_back(node->right);
                    mp[node->right].push_back(node);
                    q.push(node->right);
                 }
               }      
            } 
            unordered_set<TreeNode*> visit;
            visit.insert(target);
            q.push(target);
          
    
            while(k--){
                int sz = q.size();
                while(sz--){
                    TreeNode* node = q.front();
                    q.pop();
                    for(auto it : mp[node]){
                        if(!visit.count(it)){
                            visit.insert(it);
                            q.push(it);
                        }
                    }
                }
            }
            vector<int> ans;
            while(!q.empty()){
                TreeNode* n = q.front();
                q.pop();
                ans.push_back(n->val);
            }
            return ans;
        }
    };
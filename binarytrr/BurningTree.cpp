class Solution {
    public:
        int amountOfTime(TreeNode* root, int start) {
            unordered_map<TreeNode*, vector<TreeNode*>> adj;
            queue<TreeNode*> q;
            q.push(root);
            TreeNode* startNode = nullptr;  
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
    
                if(node->val == start) {
                    startNode = node;
                }
    
                if(node->left){
                    adj[node].push_back(node->left);
                    adj[node->left].push_back(node);
                    q.push(node->left);
                }
                if(node->right){
                    adj[node].push_back(node->right);
                    adj[node->right].push_back(node);
                    q.push(node->right);
                }
            }
            unordered_set<TreeNode*> visit;
            q.push(startNode);
            visit.insert(startNode);
            int count = 0;
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    TreeNode* node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(!visit.count(it)){
                            visit.insert(it);
                            q.push(it);
                        }
                    }
                }
                count++;
            }
            return count-1;
        }
    };
    
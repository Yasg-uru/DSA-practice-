class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
            unordered_map<TreeNode*, TreeNode*> mp;
            queue<TreeNode*> qu;
            mp[root] = NULL;
            qu.push(root);
            while(!qu.empty()) {
                TreeNode* node = qu.front();
                qu.pop();
    
                if(node->left) {
                    mp[node->left] = node;
                    qu.push(node->left);
                }
                if(node->right) {
                    mp[node->right] = node;
                    qu.push(node->right);
                }
            }
            unordered_set<TreeNode*> ancestors;
            while(p != NULL) {
                ancestors.insert(p);
                p = mp[p];
            }
            while(q != NULL) {
                if(ancestors.count(q)) {
                    return q;
                }
                q = mp[q];
            }
            return NULL; 
        }
    };
    
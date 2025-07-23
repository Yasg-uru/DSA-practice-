/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int currsize=q.size();
            while(currsize--){
                TreeNode* currnode=q.front();
                cout<<currnode->val<<endl;
                q.pop();
                level.push_back(currnode->val);
                if(currnode->left!=NULL){
                    q.push(currnode->left);
                }
                if(currnode->right!=NULL){
                    q.push(currnode->right);
                }
            }
            ans.push_back(level);
                
        }
        
    return ans;
    }
};
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
    bool isUnivalTree(TreeNode* root) {
      
        if(root==NULL){
            return false;
        }
        queue<TreeNode*>q;
        q.push(root);
        unordered_set<int>temp;
        while(not q.empty()){
            int currsize=q.size();
           
            while(currsize--){
                TreeNode* currnode=q.front();
                q.pop();
                temp.insert(currnode->val);
                if(currnode->left){
                    q.push(currnode->left);
                }
                if(currnode->right){
                    q.push(currnode->right);
                }

                
            }
        
        }
        return temp.size()>1?false:true;
    }
};
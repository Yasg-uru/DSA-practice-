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
TreeNode* dfs(TreeNode* root,set<int>&todelete,vector<TreeNode*>&res){
    if(root==nullptr){
        return root;
    }
    root->left=dfs(root->left,todelete,res);
    root->right=dfs(root->right,todelete,res);
    if(!todelete.count(root->val)>0){
     return root;
    }
    if(root->left!=nullptr){
        res.push_back(root->left);
    }
    if(root->right!=nullptr){
        res.push_back(root->right);
    }
    root->left=nullptr;
    root->right=nullptr;
    return nullptr;
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>todelete(to_delete.begin(),to_delete.end());
        vector<TreeNode*>res;
        root=dfs(root,todelete,res);
   if(root!=NULL){
    res.push_back(root);
   }
   return res;
    }
};
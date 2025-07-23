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
void path(TreeNode*  root,vector<string>&str,string s){
    
    if(root==NULL){
      return;
    }
    if(root->left==NULL and root->right==NULL){
       s+=to_string(root->val);
       str.push_back(s);
       
    }
    s+=to_string(root->val);
    path(root->left,str,s+"->");
    path(root->right,str,s+"->");
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>str;
        string s="";
        path(root,str,s);
        return str;



    }
};
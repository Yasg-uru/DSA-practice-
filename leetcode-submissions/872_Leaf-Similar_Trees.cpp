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
void rec(vector<int>&leaf,TreeNode* root){
    if(root->left==NULL and root->right==NULL){
        leaf.push_back(root->val);
        return;
    }
    rec(leaf,root->left);
    rec(leaf,root->right);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      //now we need to create function for stroing leafnodes in vector
      vector<int> l1,l2;
      rec(l1,root1);
      rec(l2,root2);
      if(l1==l2){
          return true;
      }  
      return false;

    }
};
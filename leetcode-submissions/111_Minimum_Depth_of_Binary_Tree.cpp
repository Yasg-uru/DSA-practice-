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
    int minDepth(TreeNode* root) {
      if(root==NULL){
          return INT_MAX;
      }  
      if(root->left==NULL and root->right==NULL){
        return 1;
      }
      int left=minDepth(root->left);
      int right=minDepth(root->right);
      return min(left,right)+1;
    }
};
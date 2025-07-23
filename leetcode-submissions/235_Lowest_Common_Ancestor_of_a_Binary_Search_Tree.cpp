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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root->val > p->val and root->val > q->val){
        //then moving in right subtree
        return lowestCommonAncestor(root->left,p,q);
        //cout<<root->data<<" ";
    } 
    if(root->val < p->val and root->val < q->val){
        //then moving in right subtree
        return lowestCommonAncestor(root->right,p,q);
    } 
    //cout<<root->data<<" ";
    return root; 
    }
};
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
        if(not root) return root;
        if(root==p or root==q) return root;
        TreeNode* leftNode = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode =lowestCommonAncestor(root->right, p,q);
        //cases
        if(leftNode && rightNode)
            return root;
        
        else if(leftNode and not rightNode)
            return leftNode ;
        
        return rightNode;
    }
};
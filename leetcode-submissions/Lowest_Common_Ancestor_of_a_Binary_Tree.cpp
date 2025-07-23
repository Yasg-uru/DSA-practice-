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
        if(not root){
            return root ;
        }
        if(p->val == root->val or q->val == root->val){
            return root ;
        }
        TreeNode* left = lowestCommonAncestor(root->left ,p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p , q);
        if(left and right){
            return root ;
        }else if(left and not right){
            return left ;
        }else{
            return right ;
        }
    }
};
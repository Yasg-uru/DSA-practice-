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
    
    int preorder(TreeNode* root, int maxPath){
        if(not root) return 0 ;
        int result= root->val>=maxPath?1:0;
        maxPath= max(maxPath,root->val);
        int leftResult = preorder(root->left,maxPath);
        int rightResult = preorder(root->right,maxPath);
        return result+leftResult+rightResult;
    }
    int goodNodes(TreeNode* root) {
        return preorder(root,root->val);
    }
};
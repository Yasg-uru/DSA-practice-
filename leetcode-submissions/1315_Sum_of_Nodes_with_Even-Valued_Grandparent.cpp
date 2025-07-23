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
    int solve(TreeNode* root,TreeNode* parent=nullptr, TreeNode* grandParent= nullptr){
        if(not root) return 0 ;
        int currSum =0;
        if(grandParent and grandParent->val%2==0){
currSum+=root->val;
        }
        currSum+=solve(root->left,root,parent);
        currSum+=solve(root->right,root,parent);
        return currSum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root);
    }
};
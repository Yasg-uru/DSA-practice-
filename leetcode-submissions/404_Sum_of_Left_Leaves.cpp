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
void sumofall(TreeNode*  root,int &sum){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL and root->left->right==NULL and root->left_left==NULL){
        sum+=root->left->val;
    }
    sumofall(root->left,sum);
    sumofall(root->right,sum);
}
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        sumofall(root,sum);
        return sum;
    }
};
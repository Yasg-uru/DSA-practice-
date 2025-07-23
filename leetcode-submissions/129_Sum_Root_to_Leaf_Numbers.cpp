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
void helper(TreeNode* root,long num,long &sum){
    if(root==nullptr){
        return ;
    }
    num+=root->val;
    if(root->left==nullptr and root->right==nullptr){
        sum+=num;
    }
    helper(root->left,num*10,sum);
    helper(root->right,num*10,sum);
}
    int sumNumbers(TreeNode* root) {
        //in this code we are uisng the recursive inorder wise approach that can able to solve this question eqasy 
        long num =0;
        long sum=0;
        helper(root,num,sum);
        return sum;
    }
};
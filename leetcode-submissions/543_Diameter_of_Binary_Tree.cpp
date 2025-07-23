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
int ans=0;
int helper(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int left_height=helper(root->left);
    int right_height=helper(root->right);
    ans=max(ans,left_height+right_height);
    return 1+max(left_height,right_height);

}
    int diameterOfBinaryTree(TreeNode* root) {
       helper(root);
       return ans; 
    }
};
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
int  moves;
int dfs(TreeNode* root){
       if(root==NULL){
            return 0;

        }
        int leftmove=dfs(root->left);
        int rightmove=dfs(root->right);
        root->val=leftmove+rightmove+(root->val-1);
        moves+=abs(root->val);
        return root->val;

}

    int distributeCoins(TreeNode* root) {
        moves=0;
     dfs(root);
     return moves;
    }
};
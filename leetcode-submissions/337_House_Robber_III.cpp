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
int f(TreeNode* root,bool isrobbed){
    //base case
    if(root==NULL){
        return 0;
    }
    if(isrobbed){
        int ans=f(root->left,false)+f(root->right,false);
        return ans;
    }else{
        int c1=root->val+f(root->left,true)+f(root->right,true);
        int c2=f(root->left,false)+f(root->right,false);
        return max(c1,c2);
    }
}
    int rob(TreeNode* root) {
        return f(root,false);
    }
};
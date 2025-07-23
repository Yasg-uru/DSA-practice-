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
    int res=0;
    int helper(TreeNode* root){
        if(not root) return 0;
        int leftSum = helper(root->left);
        int rightSum=helper(root->right);
        res+=abs(rightSum-leftSum);
        return leftSum+rightSum+root->val;

    }
    int findTilt(TreeNode* root) {
        if(not root){
            return res;

        }
        helper(root);
        return res;
    }
};
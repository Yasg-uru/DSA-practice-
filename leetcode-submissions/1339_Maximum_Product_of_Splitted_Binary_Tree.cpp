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
    long long sum =0;
    long long maxP =0;

    int totalSum(TreeNode* root){
        if(not root) return 0 ;
        int leftSum = totalSum(root->left);
        int rightSum = totalSum(root->right);
        return root->val+leftSum+rightSum;
    }
    int find (TreeNode* root){
        if(not root){
            return 0 ;
        }
        int leftSum = find(root->left);
        int rightSum = find(root->right);
        long long  subTreeSum= root->val+leftSum+rightSum ;
        int remainingTreeSum  = sum - subTreeSum ;
        maxP= max(maxP, subTreeSum*remainingTreeSum);
        return subTreeSum ;
    }
    int maxProduct(TreeNode* root) {
        if(not root) return 0 ;
        sum = totalSum(root);
        //after finding total sum we need to find the maxproduct 
        find(root);
        return maxP%1000000007;
    }
};
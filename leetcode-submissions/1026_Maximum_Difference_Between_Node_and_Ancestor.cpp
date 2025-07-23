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
    int dfs(TreeNode* root , int currMax , int currMin){
        if(not root){
            return abs(currMax-currMin);
            
        }
        currMax  = max(currMax , root->val);
        currMin  = min(currMin , root->val);
        int left = dfs(root->left , currMax , currMin);
        int right = dfs(root->right  , currMax , currMin);
        return max(left , right);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root , root->val, root->val );
        
    }
};
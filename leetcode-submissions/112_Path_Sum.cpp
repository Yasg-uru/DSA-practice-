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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        while(not q.empty()){
            auto [currNode,currSum]=q.front();
            q.pop();
            if(currSum==targetSum){
                return true ;
            }
            if(currNode->left){
                q.push({currNode->left,currSum+currNode->left->val});
            }
            if(currNode->right){
                q.push({currNode->right,currSum+currNode->right->val});
            }
        }
        return false ;
    }
};
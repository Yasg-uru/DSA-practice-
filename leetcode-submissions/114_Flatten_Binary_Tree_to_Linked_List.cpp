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
    void solve(TreeNode* root, TreeNode* &prevNode){
        if(not root) return;
        //first we will go to the right and then left because if we will traverse left first then we had not an access of left nodes 
        solve(root->right, prevNode);
        solve(root->left, prevNode);
        root->right= prevNode;
        root->left= nullptr;
        prevNode= root;
    }
    void flatten(TreeNode* root) {
        TreeNode* prevNode = nullptr ;
        if(not root) return  ;
        solve(root, prevNode);

    }
};
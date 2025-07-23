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
    vector<int>array ;

    void Inorder(TreeNode* root){
        if(not root) return ;
        Inorder(root->left);
        array.push_back(root->val);

        Inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        k--;
        Inorder(root);
        return array[k];
        
    }
};
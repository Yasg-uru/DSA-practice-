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
    set<int>s;
    void Inorder(TreeNode* root){
        if(not root){
            return ;
        }
        Inorder(root->left);
        s.insert(root->val);
        Inorder(root->right);


    }
    int findSecondMinimumValue(TreeNode* root) {
        if(not root) return -1;
        Inorder(root);
        s.erase(s.begin());
        if(s.empty()){
            return -1;
        }
return *s.begin();
    }
};
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
    TreeNode* subRootNode ;
    
    void Inorder(TreeNode* root,TreeNode*& subRoot){
        if(not root) return ;
        Inorder(root->left,subRoot);
        if(root->val==subRoot->val){
            subRootNode=root;
        }
        Inorder(root->right,subRoot);
    }
    void PreOrder(TreeNode* root,vector<int>&nodes){
if(not root) return ;
nodes.push_back(root->val);
PreOrder(root->left,nodes);
PreOrder(root->right,nodes);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        Inorder(root,subRoot);
    vector<int>nodes1;
    vector<int>nodes2;
    PreOrder(subRoot,nodes1);
    PreOrder(subRootNode,nodes2);
    return nodes1==nodes2;
    
    }
};
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
    void Inorder(TreeNode* root,vector<int>&nodes){
        if(not root) return ;
        Inorder(root->left,nodes);
        nodes.push_back(root->val);
        Inorder(root->right,nodes);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(not root) return root;
        vector<int>nodes;
        Inorder(root,nodes);
        TreeNode* rootNode= new TreeNode(-1);
        TreeNode* tempNode = rootNode;
        for(int i=0;i<nodes.size();i++){
            tempNode->right=new TreeNode(nodes[i]);
            tempNode=tempNode->right;
        }
        return rootNode->right;
    }
};
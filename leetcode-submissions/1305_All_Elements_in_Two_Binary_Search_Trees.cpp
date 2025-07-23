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
    void Inorder(TreeNode* root, vector<int>&nodes)
    {
        if(not root) return ;
        Inorder(root->left, nodes);
        nodes.push_back(root->val);
        Inorder(root->right, nodes);

    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>nodes;
        Inorder(root1,nodes);
        Inorder(root2,nodes);
        sort(nodes.begin(),nodes.end());
        return nodes;
    }
};
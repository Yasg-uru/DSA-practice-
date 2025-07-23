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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(not root) return 0 ;
    vector<int>nodes;
        Inorder(root,nodes);
       
        int sum =0;
        for(int i=0;i<nodes.size();i++){
            if(nodes[i]>=low and nodes[i]<=high){
                sum+=nodes[i];
            }
        }
        return sum ;
    }
};
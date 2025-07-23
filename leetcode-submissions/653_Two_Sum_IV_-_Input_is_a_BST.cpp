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
    void Inorder(TreeNode* root, vector<int>&nodes){
        if(not root) return ;
        Inorder(root->left,nodes);
        nodes.push_back(root->val);
        Inorder(root->right, nodes);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>nodes;
        Inorder(root, nodes);
        int left =0;
        int right =nodes.size()-1;
        while(left<right){
            int sum = nodes[left]+nodes[right];
            if(sum==k){ return true;} 
            else if(sum>k){
                right--;
            }else {
                left++;
            }
        }
        return false;
    }
};
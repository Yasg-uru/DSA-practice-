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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        TreeNode* currnode=root;
        TreeNode* key=new TreeNode(val);
        while(true){
            if(currnode==NULL){
                return NULL;
            }
            if(currnode->val==val){
                break;
            }
            if(currnode->val>val){
                currnode=currnode->left;
            }else{
                currnode=currnode->right;
            }
        }
        return currnode;
    }
};
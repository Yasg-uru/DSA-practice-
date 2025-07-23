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
TreeNode* jstml(TreeNode* root){
    while(root->right){
        root=root->right;
    }
    return root;
}
TreeNode* modifyroot(TreeNode* root,int key){
if(root==NULL){
            return root;
        }else if(root->val<key){
            root->right=modifyroot(root->right,key);
        }else if(root->val>key){
            root->left=modifyroot(root->left,key);
        }else{
            if(root->val==key and root->right==NULL and root->right==NULL){
                root=NULL;
                return NULL;
                
            }else if(root->left==NULL){
                root->val=root->right->val;
                root->right=NULL;
            }else if(root->right==NULL){
                root->val=root->left->val;
                root->left=NULL;
            }else{
                TreeNode* justsmallernode=jstml(root->left);
                root->val= justsmallernode->val;
               root->left=modifyroot(root->left,justsmallernode->val);

            }

        }
        return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        root=modifyroot(root,key);
        return root;
    }
};
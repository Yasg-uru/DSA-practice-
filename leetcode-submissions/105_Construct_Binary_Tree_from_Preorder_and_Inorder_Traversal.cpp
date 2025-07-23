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
    TreeNode* buildtreehelper(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>mp){
        //base case 
        if(prestart>preend or instart>inend){
            return NULL;
        }
        int rootindex=mp[preorder[prestart]];
        //now we have to find left subtree elements
        int leftsubtreele=rootindex-instart;
     TreeNode* root=new  TreeNode(preorder[prestart]);
     root->left=buildtreehelper(preorder,prestart+1,prestart+leftsubtreele,inorder,instart,rootindex-1,mp);
     root->right=buildtreehelper(preorder,prestart+leftsubtreele+1,preend,inorder,rootindex+1, inend,mp);
     return root;
        
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     unordered_map<int,int>mp;
     for(int i=0;i<inorder.size();i++){
         mp[inorder[i]]=i;//storing the index and element

     }  
     TreeNode* root=buildtreehelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
     return root; 
    }
};
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
 TreeNode* bstbuilder(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&mp){
     if(prestart>preend or instart>inend){
         return NULL;
     }
      TreeNode* root=new  TreeNode(preorder[prestart]);
     int rootindex=mp[preorder[prestart]];
     int leftsubtree=rootindex-instart;
     root->left=bstbuilder(preorder,prestart+1,prestart+leftsubtree,inorder,instart,rootindex-1,mp);
     root->right=bstbuilder(preorder,prestart+leftsubtree+1,preend,inorder,rootindex+1,inend,mp);
     return root;

 }
     
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;

         sort(inorder.begin(),inorder.end());
         unordered_map<int,int>mp;
         for(int i=0;i<inorder.size();i++){
             mp[inorder[i]]=i;
         }
      return  bstbuilder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};
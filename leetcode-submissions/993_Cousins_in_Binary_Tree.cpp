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
    bool isCousins(TreeNode* root, int x, int y) {
       if(root==nullptr){
           return false;
       }
       queue<pair<TreeNode*,pair<int,int>>>q;
       q.push({root,{0,0}});
       int parentx,parenty;
       int levelx,levely;

       while(not q.empty()){
           int currsize=q.size();
           while(currsize--){


           
           TreeNode* currnode=q.front().first;
           int parent=q.front().second.second;
           int level=q.front().second.first;
           q.pop();
           if(currnode->val==x){
               levelx=level;
               parentx=parent;
           }
           if(currnode->val==y){
               levely=level;
               parenty=parent;

           }
           if(currnode->right){
               q.push({currnode->right,{level+1,currnode->val}});
           }
           if(currnode->left){
               q.push({currnode->left,{level+1,currnode->val}});
           }

       }
       }
       if(levelx==levely){
           if(parentx!=parenty){
               return true;
           }
       }
       return false;
    }
};
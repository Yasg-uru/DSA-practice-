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
    TreeNode* LCA(TreeNode* root,int src,int dest){
        //base case if root is null or we finds the destination and source then 
        if(root==nullptr or root->val==src or root->val==dest){
            return root;
        }
        //finding the left and right node 
        TreeNode* left=LCA(root->left,src,dest);
        TreeNode* right=LCA(root->right,src,dest);
        if(left==nullptr){
            return right;
        }else if(right==nullptr){
            return left;
        }
        return root;
    }
    bool FindPath(TreeNode* root,int target,string& path){
        if(root==NULL){
            return false;
        }
        if(root->val==target){
            return true ;

        }
        path.push_back('L');
        if(FindPath(root->left,target,path)){
            return true ;

        }
        path.pop_back();

        path.push_back('R');
        if(FindPath(root->right,target,path)){
            return true ;
            
        }
        path.pop_back();
        return false;


    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
      //first we need to find the lca between the source to destination after it we need to creaate a logic of recursion and backtracking 
      TreeNode* lca=LCA(root,startValue,destValue);
      string startstring="";
      FindPath(lca,startValue,startstring);
      string deststring="";
      FindPath(lca,destValue,deststring);
      string res="";

      for(int i=0;i<startstring.size();i++){
res.push_back('U');

      }
      for(char ele:deststring){
        res.push_back(ele);
      }
      return res;


    }
};
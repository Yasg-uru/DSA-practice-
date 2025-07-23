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
     vector<TreeNode*> solve(int n ){
        if(n%2==0) return {}; //event can't make a full binary tree
        if(n==1) {
            TreeNode* root= new TreeNode(0);
            return {root};
        }
         vector<TreeNode*> result ;
         for(int i=1;i<n;i+=2){ // skipping the even numbers 
          vector<TreeNode*> left= solve(i) ; //int left we have i number of nodes 
           vector<TreeNode*> right = solve(n-i-1) ;// in the right we have n-i-1 number of nodes
           for(TreeNode* l :left){
            for(TreeNode* r:right){
                TreeNode* root = new TreeNode(0);
                root->left = l;
                root->right = r;
                result.push_back(root);
            }
           }

         }
         return result;
     }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};
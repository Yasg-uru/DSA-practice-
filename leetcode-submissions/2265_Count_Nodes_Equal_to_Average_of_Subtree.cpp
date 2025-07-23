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
    int count =0;
    pair<int,int> getNodes(TreeNode* root  ){
        //base case 
        if(not root) return {0 ,0 };
        pair<int,int> left = getNodes(root->left);
        pair<int,int>right= getNodes(root->right);
        int totalSum = root->val+left.first+right.first;
        int totalNodes = 1+left.second +right.second;
        return {totalSum , totalNodes};
    }
   
    int averageOfSubtree(TreeNode* root) {
       if(not root) return 0 ;
       pair<int,int>data= getNodes(root);
       int count =( root->val==data.first/data.second)?1:0;
       return count+ averageOfSubtree(root->left) +averageOfSubtree(root->right);
    }
};
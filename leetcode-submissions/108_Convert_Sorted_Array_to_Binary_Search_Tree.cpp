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
     TreeNode* createbst(vector<int>&arr,int start,int end){
         if(start>end){
             return NULL;
         }
         int mid=(start+end)/2;
          TreeNode* root=new  TreeNode(arr[mid]);
          root->left=createbst(arr,0,mid-1);
          root->right=createbst(arr,mid+1,end);
          return root;
     }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       TreeNode* root=createbst(nums,0,nums.size()-1);
       return root;
    }
};
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
    TreeNode* BuildTree(vector<int>&nums, int start , int end){
        if(start>end) return nullptr;
        int maxEleIndex=-1;
        int maxElement =INT_MIN;
        for(int i=start;i<=end;i++){
            if(maxElement<nums[i]){
                maxElement= nums[i];
                maxEleIndex= i;
            }
        }
        TreeNode* root=new TreeNode(nums[maxEleIndex]);
        root->left=BuildTree(nums,start, maxEleIndex-1);
        root->right= BuildTree(nums,maxEleIndex+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int start =0;
        int end =nums.size()-1;
        return BuildTree(nums,start, end);
    }
};
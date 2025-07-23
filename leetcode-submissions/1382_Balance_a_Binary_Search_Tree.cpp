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
vector<int>inorderarray;
void inorder(TreeNode* root){

if(!root){
    return ;
}
inorder(root->left);
inorderarray.push_back(root->val);
inorder(root->right);
}
TreeNode* createtree(int start,int end){
    if(start>end){
        return nullptr;
    }
    int mid=start+(end-start)/2;
    TreeNode* root=new TreeNode(inorderarray[mid]);
    root->left=createtree(start,mid-1);
    root->right=createtree(mid+1,end);
    return root;

}
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
return createtree(0,inorderarray.size()-1);

    }
};
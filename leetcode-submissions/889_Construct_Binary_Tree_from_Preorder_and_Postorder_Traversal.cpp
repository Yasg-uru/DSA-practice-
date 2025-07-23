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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preStart = 0 ;
        int preEnd = postorder.size()-1;
        int postStart = 0;
        return solve(preorder, postorder, preStart , preEnd , postStart);
    }
private:
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int preStart , int preEnd , int postStart){
        if(preStart>preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd) return root;
        int j=postStart ;
        while(j<preorder.size() and postorder[j]!=preorder[preStart+1]) j++;
        int leftSize= j-postStart+1;
        root->left = solve(preorder, postorder, preStart+1,  leftSize+preStart, postStart);
        root->right = solve(preorder, postorder, preStart+leftSize+1, preEnd, j+1);
        return root;

    }
};
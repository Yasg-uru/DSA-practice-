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
        int maxAns = INT_MIN;
        int solve(TreeNode* root){
            if(not root) return 0;
            int left= solve(root->left);
            int right = solve(root->right);
            int sirf_root = root->val;
            int koiEk = max(left,right)+root->val;
            int kahisebhi =  left+right+root->val;
            maxAns = max(maxAns, kahisebhi);
            return max(sirf_root,koiEk);


        }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxAns ;
    }
};
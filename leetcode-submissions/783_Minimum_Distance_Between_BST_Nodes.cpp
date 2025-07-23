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
    int minDiffInBST(TreeNode* root) {
        int mindist=INT_MAX;
        queue<TreeNode*>q;
        q.push(root);
        while(not q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* currnode=q.front();
                q.pop();
                if(currnode->left and currnode->right){
                    mindist=min(mindist,abs(currnode->right->val-currnode->left->val));
                }
                if(currnode->left){
                    mindist=min(mindist,abs(currnode->val-currnode->left->val));
                    q.push(currnode->left);
                }
                if(currnode->right){
                    mindist=min(mindist,abs(currnode->val-currnode->right->val));
                    q.push(currnode->right);
                }
            }
        }
        return mindist;
    }
};
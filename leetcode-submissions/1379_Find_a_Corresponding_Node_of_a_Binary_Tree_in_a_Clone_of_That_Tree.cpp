/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(cloned);
        while(not q.empty()){
            TreeNode* currNode =q.front();
            q.pop();
            if(currNode->val==target->val){
                return currNode;
            }
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);

            }

        }
        return new TreeNode(-1);

    }
};
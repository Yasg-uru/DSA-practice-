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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool end = false;
        while(not q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            if(!currNode){
                end = true ;
            }
            else{
                if(end==true){
                    return true ;
                }
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return true ;
    }
};
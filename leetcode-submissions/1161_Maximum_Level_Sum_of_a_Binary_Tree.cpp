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
    int maxLevelSum(TreeNode* root) {
        if(not root) return 0 ;
        queue<TreeNode*>q;
        q.push(root);
        int maxLevel=0;
        int levels =1;
        int maxLevelSum =0;

        while(not q.empty()){
            int size = q.size();
            int  currSum =0;
            while(size--){
                TreeNode* currNode= q.front();
                currSum+=currNode->val;
                q.pop();
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            if(currSum>maxLevelSum){
                maxLevel=levels;
                maxLevelSum= currSum;
                
            }
            levels++;
        }
        return maxLevel;
    }
};
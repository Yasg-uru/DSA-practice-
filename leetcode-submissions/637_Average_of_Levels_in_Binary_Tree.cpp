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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back(root->val);
        while(not q.empty()){
            TreeNode* currnode=q.front();
            q.pop();
            double leftval,rightval;

            if(currnode->left and currnode->right){
                q.push(currnode->left);
                leftval=currnode->left->val;
                q.push(currnode->right);
                rightval=currnode->right->val;
                double answer=(leftval+rightval)/2;
            ans.push_back(answer);
            }
           
        }
return  ans;
    }
};
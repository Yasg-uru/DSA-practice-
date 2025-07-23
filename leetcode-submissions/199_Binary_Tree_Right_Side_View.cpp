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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int currsize=q.size();
            while(currsize!=0){
                    TreeNode* currnode=q.front();
                    q.pop();
                if(currsize==1){
                    ans.push_back(currnode->val);
                }
                if(currnode->left){
                    q.push(currnode->left);
                }
                if(currnode->right){
                    q.push(currnode->right);
                }
                currsize--;

            }

        }
        return ans;
    }
};
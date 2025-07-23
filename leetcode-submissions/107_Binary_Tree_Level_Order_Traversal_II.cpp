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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        
        q.push(root);
        while(not q.empty()){
            int currsize=q.size();
            vector<int>level;

            while(currsize--){
                TreeNode* currnode=q.front();
                q.pop();
                level.push_back(currnode->val);
                if(currnode->left){
                    q.push(currnode->left);

                }
                if(currnode->right){
                    q.push(currnode->right);
                }

            }
                ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
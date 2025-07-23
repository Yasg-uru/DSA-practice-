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
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(not q.empty()){
            int size=q.size();
            vector<int>temp;
            while(size--){
                TreeNode* currnode=q.front();
                temp.push_back(currnode->val);

                q.pop();
                if(currnode->left){
                    q.push(currnode->left);

                }
                if(currnode->right){
                    q.push(currnode->right);
                }
            }
            ans.push_back(temp);
        }
        int lastindex=ans.size()-1;
        return ans[lastindex][0];
    }
};
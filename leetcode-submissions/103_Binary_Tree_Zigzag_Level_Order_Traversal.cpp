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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(not q.empty()){
            int currsize=q.size();
            vector<int>temp;
            while(currsize--){
                TreeNode* currnode=q.front();
                q.pop();
                temp.push_back(currnode->val);
                if(currnode->left){
                    q.push(currnode->left);
                }
                if(currnode->right){
                    q.push(currnode->right);
                }

                
            }
            ans.push_back(temp);
        }
        for(int i=1;i<ans.size();i+=2){
            swap(ans[i][0],ans[i][1]);
        }
return ans;
    }

};
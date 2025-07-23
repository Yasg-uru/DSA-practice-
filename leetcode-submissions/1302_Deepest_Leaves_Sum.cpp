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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans ;
        while(not q.empty()){
            int currSize=q.size();
            vector<int>temp;

            while(currSize--){
                TreeNode* currNode =q.front();
                q.pop();
                temp.push_back(currNode->val);
                if(currNode->left){
                    q.push(currNode->left);

                }
                 if(currNode->right){
                    q.push(currNode->right);

                }

            }
            ans.push_back(temp);
        }
        int DeapestLeaveSum=0;
        vector<int>lastlevelNodes =ans[ans.size()-1];
        for(int i=0;i<lastlevelNodes.size();i++){
            DeapestLeaveSum+=lastlevelNodes[i];
        }
        return DeapestLeaveSum;
    }
};
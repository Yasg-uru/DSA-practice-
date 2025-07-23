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
    int sumRootToLeaf(TreeNode* root) {
        if(not root) return 0 ;
        queue<pair<TreeNode* , string>>q;
        q.push({root,""});
        int ans =0;
        while(not q.empty()){
            auto [currNode , currPath]=q.front();
            q.pop();
            string currVal= to_string(currNode->val);
            if(not currNode->left and not currNode->right){
                int number = stoi(currPath+currVal,0,2);
                ans+=number;
            }
            if(currNode->left){
                q.push({currNode->left,currPath+currVal});
            }
            if(currNode->right){
                q.push({currNode->right,currPath+currVal});
            }
        }
        return ans ;
    }
};
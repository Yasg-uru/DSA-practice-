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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(not root)return ans ;
        queue<pair<TreeNode*,pair<vector<int>, int>>>q; //this stores the currNode -> currSum
        q.push({root,{{root->val},root->val}});
        while(not q.empty()){
            int currSize =q.size();
            // vector<int>temp;

            while(currSize--){
                auto [currNode,p]=q.front();
                q.pop();
                vector<int>currPath = p.first ;
                int currSum = p.second ;

                if(not currNode->left and not currNode->right and currSum==targetSum ){
                    ans.push_back(currPath);
                }
                if(currNode->left){
                    vector<int>newPath= currPath;
                    newPath.push_back(currNode->left->val);
                    q.push({currNode->left, {newPath,currSum+currNode->left->val}});

                }
                if(currNode->right){
                    vector<int>newPath= currPath;
                    newPath.push_back(currNode->right->val);
                    q.push({currNode->right, {newPath,currSum+currNode->right->val}});

                }
            }
        } 
        
return ans ;

    }
};
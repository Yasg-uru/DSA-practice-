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
    unordered_map<int,int>mp;
    void Inorder(TreeNode* root){
        if(not root) return ;
        Inorder(root->left);
        mp[root->val]++;
        Inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        Inorder(root);
        vector<int>ans ;
        if(mp.size()==1){
            ans.push_back(root->val);
            return ans ;
        }
        for(auto ele :mp){
            if(ele.second>1){
                ans.push_back(ele.first);
            }
        }
        return ans ;
    }
};
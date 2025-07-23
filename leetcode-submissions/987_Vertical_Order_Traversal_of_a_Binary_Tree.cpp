/*
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
    map<int,map<int,vector<int>>>mp;
    void levelorder(TreeNode* root){
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
           
            pair<TreeNode*,pair<int,int>>front=q.front();
            q.pop();
            TreeNode* node=front.first;
            int vertical_distance=front.second.second;
            int horizontal_distance=front.second.first;
            mp[horizontal_distance][vertical_distance].push_back(node->val);
            if(node->left!=NULL){
                q.push({node->left,{horizontal_distance-1,vertical_distance+1}});
            }
             if(node->right!=NULL){
                q.push({node->right,{horizontal_distance+1,vertical_distance+1}});
            }
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        levelorder(root);
        for(auto &it:mp){
            vector<int>curr;
            for(auto &i:it.second){
                sort(i.second.begin(),i.second.end());
                for(int j=0;j<i.second.size();j++){
                    curr.push_back(i.second[j]);
                }
            }
            ans.push_back(curr);
        }
        return ans;
       
        


    }
};
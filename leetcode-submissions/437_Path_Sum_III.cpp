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
int pathsumhelper(TreeNode* root,int target,int currsum,unordered_map<int,int>mp){
   
    if(root==NULL){
        return 0;
    }
    int anscount=0;
    currsum+=root->val;
    anscount=mp[currsum-target];
    mp[currsum]++;
    anscount+=pathsumhelper(root->left,target,currsum,mp);
    anscount+=pathsumhelper(root->right,target,currsum,mp);
    mp[currsum]--;//concept of backtracking is used
    return anscount;


}
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=pathsumhelper(root,targetSum,0,mp);
        return ans;
    }
};
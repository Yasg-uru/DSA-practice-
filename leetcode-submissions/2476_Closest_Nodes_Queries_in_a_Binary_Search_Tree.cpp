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
    void inorder(TreeNode* root, vector<int>&nodes){
        if(not root) return ;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>sortedValues ;
        inorder(root, sortedValues);
        vector<vector<int>>ans ;
        for (int q : queries) {
        int mini = -1, maxi = -1;
        
       
        auto it = upper_bound(sortedValues.begin(), sortedValues.end(), q);
        if (it != sortedValues.begin()) mini = *(it - 1);
        
        
        auto it2 = lower_bound(sortedValues.begin(), sortedValues.end(), q);
        if (it2 != sortedValues.end()) maxi = *it2;

        ans.push_back({mini, maxi});
    }
    return ans ;
    
    }
};
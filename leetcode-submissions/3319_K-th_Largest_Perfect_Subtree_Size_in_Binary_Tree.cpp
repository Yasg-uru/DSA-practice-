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
    int solve(TreeNode* root, vector<int>&nodes){
        if(not root) return 0;
        int left= solve(root->left, nodes);
        int right  = solve(root->right,nodes);
        if(left==right){
            int totalNodes = 1+left+right;
            nodes.push_back(totalNodes);
            return totalNodes;
        }
        return -1 ;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int>nodes;
        solve(root, nodes);
        if(nodes.size()<k) return -1;
        sort(nodes.begin(),nodes.end(),greater<int>());
        return nodes[k-1];
    }
};
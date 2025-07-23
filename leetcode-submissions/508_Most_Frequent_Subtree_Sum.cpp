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
    int solve(TreeNode* root , unordered_map<int , int>&sumFreq){
        if(not root) return  0 ;
        int  leftSum = solve(root->left, sumFreq);
        int rightSum = solve(root->right, sumFreq);
        int totalSum = root->val+leftSum +rightSum ;
        sumFreq[totalSum]++;
        return totalSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(not root) return {};
        unordered_map<int, int>sumFreq;
        solve(root,sumFreq);
        int maxFreq =0;
        for(auto& ele : sumFreq){
            maxFreq=max(maxFreq, ele.second);
        }
        vector<int>ans ;
        for(auto& ele : sumFreq){
            if(ele.second==maxFreq){
                ans.push_back(ele.first);
            }
        }
        return ans ;

    }
};
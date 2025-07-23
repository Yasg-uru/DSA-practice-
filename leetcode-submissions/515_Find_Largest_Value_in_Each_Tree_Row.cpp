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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans ;
        queue<TreeNode*>q;
        q.push(root);
        while(not q.empty()){
            vector<int>temp;

            int currSize=q.size();
            while(currSize--){
                TreeNode * currNode =q.front();
                q.pop();
                temp.push_back(currNode->val);
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);


                }

                
            }
            int maxEle=*max_element(temp.begin(),temp.end());
            ans.push_back(maxEle);
        }
        return ans ;
    }
};
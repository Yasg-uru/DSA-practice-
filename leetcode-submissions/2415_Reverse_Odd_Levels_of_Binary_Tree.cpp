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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(not q.empty()){
            vector<TreeNode*>temp;
            int currSize=q.size();
            while(currSize--){
                TreeNode* currNode=q.front();
                q.pop();
                temp.push_back(currNode);
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }

            }

            if(level%2==1){
                int right=temp.size()-1;
                int left=0;
                while(left<right){
                    int x=temp[left]->val;
                    temp[left]->val=temp[right]->val;
                    temp[right]->val=x;
                    left++;
                    right--;

                }
            }
            level++;
        }
        return root;
    }
};
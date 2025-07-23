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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        //simple we need to traverse level order and then calculate the current level sum and store it in the max heap and then after that we need to find kth level and then return the calculated sum 
        priority_queue<int >pq;
        queue<TreeNode*>q;
        q.push(root);
        while(not q.empty()){
            int currentLevel=q.size();
            int currSum=0;
            while(currentLevel--){
                TreeNode* currNode=q.front();
                q.pop();
                //after that we need to calculate the current level sum 
                currSum+=currNode->val;
                //after that 
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }

            }
            pq.push(currSum);
        }
        k-=1;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};
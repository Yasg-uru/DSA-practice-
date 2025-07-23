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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // we need to calculate the first the level order sum and after that we need to substract it with the siblings of that 
        if(!root)return root;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>levelOrderSum;
        while(not q.empty()){
            int n=q.size();
            int sum=0;

            while(n--){
                TreeNode* currNode=q.front();
                q.pop();
                sum+=currNode->val;

                
                //after that we need to calculate the sum 
                if(currNode->left){
                    q.push(currNode->left);

                }
                if(currNode->right){
                    q.push(currNode->right);
                }
                //after that we need to push that sum in the levelorder sum vector 

            }
            levelOrderSum.push_back(sum);



        }
        // we have to find out the siblings sum and substract it to the levelorder sum 
        int i=1;
        root->val=0;

        q.push(root);
        //after that we need to traverse 
        while(not q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* currNode=q.front();
                q.pop();
                //after that we need to calculate the siblings
                int siblingSum=0;
                if(currNode->left){
                    siblingSum+=currNode->left->val;
                }
                if(currNode->right){
                    siblingSum+=currNode->right->val;
                }
                //after adding we need to substract it to the currLevel sum 
                if(currNode->left){
                    currNode->left->val=levelOrderSum[i]-siblingSum;
                    q.push(currNode->left);

                }
                if(currNode->right){
                    currNode->right->val=levelOrderSum[i]-siblingSum;
                    q.push(currNode->right);
                }

            }
            i++;
        }
        return root;
    }
};
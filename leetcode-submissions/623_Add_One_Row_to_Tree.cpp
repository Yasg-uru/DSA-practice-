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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // we can solve thiis question by uisng the simple bfs approach that can able to solve this question very easily i have very simple level order approach
        if(depth==1){
            //now creating the new node of the value
            TreeNode* newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }

        // we handled the base case conditions that can able to handle the corner cases
        //now creatint the queue<node , depth>
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(not q.empty()){
            int currsize=q.size();
            while(currsize--){
                TreeNode* currnode=q.front().first;
                int d=q.front().second;
                q.pop();
                if(currnode->left){
                    q.push({currnode->left,d+1});
                }
                if(currnode->right){
                    q.push({currnode->right,d+1});
                }

                //now handling the case of the insertion of the new node 
                if(depth-1==d){
                    //now depth of the tree is equal to the depth-1 then wee need to insert the nodes of the value
                    TreeNode* newnodeL=new TreeNode(val);
                    newnodeL->left=currnode->left;
                    TreeNode* newnodeR=new TreeNode(val);
                    newnodeR->right=currnode->right;
                    currnode->right=newnodeR;
                    currnode->left=newnodeL;

                }
                if(d>=depth){
                   break;
                }
                

            }
        }
return root;
    }
};
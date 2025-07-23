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
    int widthOfBinaryTree(TreeNode* root) {
        int maxwidth=INT_MIN;
        queue<pair<TreeNode*,int>>q;
        if(root==nullptr){
            return 0;
        }
        //we are storing the (node,index);
        //for left 2*(index-1)+1 and for right 2*(index-1)+1;
        q.push({root,0});
        //initial index is 0 and node is root
        int ans=0;
        while(not q.empty()){
            int size=q.size();
            int left,right;
            for(int i=0;i<size;i++){
                TreeNode* currnode=q.front().first;
                int currindex=q.front().second;
                q.pop();
                if(i==0){
                    left=currindex;
                }
                if(i==size-1){
                    right=currindex;
                }
                if(currnode->left){
                    q.push({currnode->left,(2*(currindex-1)+1)});
                }
                if(currnode->right){
                    q.push({currnode->right,(2*(currindex-1)+2)});
                }
            }
            ans=max(ans,(right-left+1));

        }
        return ans;
    }
};
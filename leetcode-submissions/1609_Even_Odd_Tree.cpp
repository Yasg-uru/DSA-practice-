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
    bool isEvenOddTree(TreeNode* root) {
        //this question is easy and it is solved by using level order traversal 
        
        queue<TreeNode*>q;
        if(root==nullptr){
            return false;
        }
        q.push(root);
        int level=-1;

        while(not q.empty()){
            int currsize=q.size();
            level++;
            int prev=0;

           

            for(int i=0;i<currsize;i++){
                TreeNode* currnode=q.front();
                q.pop();
                if(level==0 and currnode->val%2==0){
                    return false;

                 
                }
                if(i==0 ){
                    if((level%2==0 and currnode->val%2==1) or (level%2==1 and currnode->val%2==0)){
                        prev=currnode->val;
                    }else{
                        return false;
                    }
                }else{
                    if(level%2==1 ){
                        if(currnode->val%2==0 and prev>currnode->val){
                            prev=currnode->val;
                        }else{
                            return false;
                        }
                    }else{
                        if(currnode->val%2==1 and prev<currnode->val){
                            prev=currnode->val;
                        }else{
                            return  false;
                        }
                    }
                }
                if(currnode->left){
                    q.push(currnode->left);

                }
                if(currnode->right){
                    q.push(currnode->right);
                }
              
            
           
        }
        }
        return true;
        
    }
};
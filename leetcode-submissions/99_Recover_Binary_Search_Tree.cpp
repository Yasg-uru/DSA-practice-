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
    void inorder(TreeNode* root , TreeNode*& prevNode , TreeNode*& firstNode , TreeNode*& middleNode , TreeNode*& lastNode ){
        if(not root) return ;
        inorder(root->left,prevNode, firstNode , middleNode ,lastNode);
        if(prevNode && prevNode->val>root->val)
        {
            if( !firstNode){
                firstNode = prevNode;
                middleNode =root;
            }else {
                lastNode = root;
            }
        }
        prevNode = root;
        inorder(root->right,prevNode, firstNode , middleNode ,lastNode);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* lastNode = nullptr , *middleNode = nullptr , *firstNode = nullptr;
        TreeNode* prevNode =nullptr;
        inorder(root, prevNode , firstNode ,middleNode ,lastNode);
        if(firstNode && lastNode){
            swap(firstNode->val,lastNode->val);
        }else if(firstNode && middleNode){
            swap(firstNode->val,middleNode->val);
        }

    }
};
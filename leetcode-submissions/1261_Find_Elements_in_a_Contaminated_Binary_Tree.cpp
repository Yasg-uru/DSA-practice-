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
class FindElements {
public:
    TreeNode* root;
    void assignValues(TreeNode* root, int x){
        if(not root) return ;
        root->val=x;
        assignValues(root->left, 2*x+1);
        assignValues(root->right, 2*x+2);
    }
    bool findTarget(TreeNode* root, int target){
         if(not root) return false;
        if(root->val==target){
            return true;
        }
        return findTarget(root->left, target) or findTarget(root->right, target); 
    }
    FindElements(TreeNode* root) {
        this->root= root;
        if(root){
            assignValues(root, 0);
        }
    }
    
    bool find(int target) {
       return findTarget(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
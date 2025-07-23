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
class BSTIterator {
public:
    vector<int>nodes;
    int index ;
    void Inorder(TreeNode* root){
        if(not root) return;
        Inorder(root->left);
        nodes.push_back(root->val);
        Inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        index=-1;
        Inorder(root);

    }
    
    int next() {
        index++;
        return nodes[index];
    }
    
    bool hasNext() {
        if(index+1<nodes.size()){
            return true ;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
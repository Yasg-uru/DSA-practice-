class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }

        int val1 = (root1 != nullptr) ? root1->val : 0;
        int val2 = (root2 != nullptr) ? root2->val : 0;

        TreeNode* root = new TreeNode(val1 + val2);

        // Check if root1->left and root2->left are not nullptr before making the recursive call
        root->left = mergeTrees((root1 != nullptr && root1->left != nullptr) ? root1->left : nullptr,
                                (root2 != nullptr && root2->left != nullptr) ? root2->left : nullptr);

        // Check if root1->right and root2->right are not nullptr before making the recursive call
        root->right = mergeTrees((root1 != nullptr && root1->right != nullptr) ? root1->right : nullptr,
                                 (root2 != nullptr && root2->right != nullptr) ? root2->right : nullptr);

        return root;
    }
};

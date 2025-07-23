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
    TreeNode* solve(int &i , int depth , string& s,int n ){
        if(i>=n) return NULL;
        int j=i;
        while(j<n and s[j]=='-'){
             j++;
        }
        int d= j-i;
        if(d!=depth){ return NULL;}
        i+=d;
        long long  num = 0 ;
        while(i<n and isdigit(s[i])){
            long long  digit = s[i]-'0';
            num= num*10+digit;
            i++;

        }
        TreeNode* root= new TreeNode(num);
        root->left = solve(i , depth+1, s, n );
        root->right = solve(i, depth+1, s , n);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        int depth = 0 ;
        return solve(i, depth, traversal, traversal.length());
    }
};
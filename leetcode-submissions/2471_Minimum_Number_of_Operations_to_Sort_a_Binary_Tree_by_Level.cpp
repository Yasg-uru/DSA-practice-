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
     int minSwapsToMakeSortedArray(vector<int>&arr){
        int n = arr.size();
    
    // Create a vector of pairs where each pair contains the array value and its index
    vector<pair<int, int>> arrWithIndex(n);
    for (int i = 0; i < n; i++) {
        arrWithIndex[i] = {arr[i], i};
    }
    
    // Sort the vector based on the array values
    sort(arrWithIndex.begin(), arrWithIndex.end());
    
    // Create a visited array to track visited elements
    vector<bool> visited(n, false);
    
    int swaps = 0;
    
    for (int i = 0; i < n; i++) {
        // Skip if the element is already visited or in the correct position
        if (visited[i] || arrWithIndex[i].second == i) {
            continue;
        }
        
        // Find the cycle size
        int cycleSize = 0;
        int x = i;
        
        while (!visited[x]) {
            visited[x] = true;
            x = arrWithIndex[x].second;
            cycleSize++;
        }
        
        // Add (cycleSize - 1) to the swap count
        if (cycleSize > 1) {
            swaps += (cycleSize - 1);
        }
    }
    
    return swaps;
     }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans =0;

        while(not q.empty()){
           int currSize=q.size();
           vector<int>temp;
           while(currSize--){
             TreeNode* curr=q.front();
            q.pop();
            temp.push_back(curr->val);
            if(curr->left){
                q.push(curr->left);

            }
            if(curr->right){
                q.push(curr->right);
                
            }
           }
           ans+=minSwapsToMakeSortedArray(temp);
        }
        return ans ;
    }
};
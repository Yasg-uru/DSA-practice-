// // Online C++ compiler to run C++ program online
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
// };
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int data;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
//  * };
//  **/

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int data;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
//  * };
//  **/

// class Solution{
// public:
//     void traversLeft(TreeNode* root, vector<int>&leftNodes ){
//         if(not root or (not root->left and not root->right)){
//             return ;
//         }

//         leftNodes.push_back(root->val);
//         if(root->left){

//         traversLeft(root->left, leftNodes);
//         }else{
//             traversLeft(root->right, leftNodes);

//         }
        

//     }
//     void traverseRight(TreeNode* root , vector<int>&rightNodes ){
//         if(not root or (not root->left and not root->right)){
//             return ;
//         }
//         rightNodes.push_back(root->val);
//         if(root->right){

//         traverseRight(root->right, rightNodes);
//         }else{
//             traverseRight(root->left, rightNodes);
//         }
//     }
//     void getBottomNodes(TreeNode* root , vector<int>&bottomNodes){
//        if(not root){
//         return ;

//        }
//         if(not root->left and  not root->right){
//             bottomNodes.push_back(root->val);
//             return ;

//         }
//         getBottomNodes(root->left, bottomNodes);
//         getBottomNodes(root->right, bottomNodes);
//     }
//     vector <int> boundary(TreeNode* root){
//     	vector<int>leftNodes , rightNodes  ,bottomNodes;
//         if(not root){
//             return {};

//         }
//         traversLeft(root, leftNodes);
        
//             traverseRight(root->right, rightNodes);
 
//         getBottomNodes(root, bottomNodes);
//         vector<int>ans;
//         for(int& node:leftNodes){
//             ans.push_back(node);
//         }
//         for(int& node:bottomNodes){
//             ans.push_back(node);
//         }
//         reverse(rightNodes.begin(), rightNodes.end());
//         for(int& node : rightNodes){
//             ans.push_back(node);
//         }
//         return ans ;
        
//     }
// };
// int main() {
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right->right = new TreeNode(6);
//     root->right->right->left = new TreeNode(7);
//     root->right->right->right = new TreeNode(8);

//     Solution sol;
//     vector<int> result = sol.boundary(root);

//     cout << "Boundary traversal: ";
//     for (int n : result) {
//         cout << n << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // Min-heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> result(N, INT_MAX);
        result[0] = 0;

        while (!pq.empty()) {
            int currWt = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for (auto& nbr : adj[currNode]) {
                int totalWt = nbr.second + currWt;
                if (result[nbr.first] > totalWt) {
                    result[nbr.first] = totalWt;
                    pq.push({totalWt, nbr.first});
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (result[i] == INT_MAX) {
                result[i] = -1;
            }
        }

        return result;
    }
};

int main() {
    int N = 5; // Number of nodes
    int M = 6; // Number of edges

    // Define edges as {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 3, 4}
    };

    Solution sol;
    vector<int> result = sol.shortestPath(N, M, edges);

    cout << "Shortest path from node 0 to all nodes:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}

/*
    Problem: Validate Binary Tree Nodes (LeetCode 1361)
    Approach: Graph + BFS Traversal

    - Construct a directed graph using adjacency list representation.
    - Maintain a map to track the parent of each node to ensure a valid tree structure.
    - Use BFS to verify if all nodes can be visited from a single root.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BFS function to check if the tree is connected and has no cycles
    int BFS(unordered_map<int, vector<int>>& adj, int root) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(root);
        visited.insert(root);
        int nodesCount = 0;

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            nodesCount++;

            for (int& neighbor : adj[currNode]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return nodesCount;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> childToParent;

        // Construct adjacency list and track parent-child relationships
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (childToParent.count(leftChild[i])) return false; // Multiple parents detected
                childToParent[leftChild[i]] = i;
                adj[i].push_back(leftChild[i]);
            }
            if (rightChild[i] != -1) {
                if (childToParent.count(rightChild[i])) return false; // Multiple parents detected
                childToParent[rightChild[i]] = i;
                adj[i].push_back(rightChild[i]);
            }
        }

        // Find the root node (a node without a parent)
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!childToParent.count(i)) {
                if (root != -1) return false; // More than one root found
                root = i;
            }
        }

        // If no root is found, return false
        if (root == -1) return false;

        // Validate if the tree is connected and has exactly `n` nodes
        return BFS(adj, root) == n;
    }
};

// Example Usage
int main() {
    Solution solution;
    vector<int> leftChild = {1, -1, 3, -1};
    vector<int> rightChild = {2, -1, -1, -1};
    int n = 4;
    cout << "Is Valid Tree: " << solution.validateBinaryTreeNodes(n, leftChild, rightChild) << endl;
    return 0;
}

#include <unordered_map>
#include <queue>

using namespace std;

// Generic Node Structure (Modify as needed for Graph, Tree, or Linked List)
class Node {
public:
    int val;
    vector<Node*> neighbors; // Change to left/right for Trees, or next for Linked Lists
    Node(int _val) {
        val = _val;
    }
};

class Solution {
public:
    // HashMap to store original → cloned mapping
    unordered_map<Node*, Node*> cloneMap;

    // DFS Traversal (Recursion-based cloning)
    Node* cloneDFS(Node* originalNode) {
        if (!originalNode) return nullptr;
        
        // If already cloned, return the existing clone
        if (cloneMap.find(originalNode) != cloneMap.end()) {
            return cloneMap[originalNode];
        }

        // Create a new clone
        Node* clonedNode = new Node(originalNode->val);
        cloneMap[originalNode] = clonedNode;

        // Recursively clone the neighbors (or left/right in Tree)
        for (auto& neighbor : originalNode->neighbors) {
            clonedNode->neighbors.push_back(cloneDFS(neighbor));
        }

        return clonedNode;
    }

    // BFS Traversal (Queue-based cloning)
    Node* cloneBFS(Node* originalNode) {
        if (!originalNode) return nullptr;

        // Create a clone for the first node
        Node* clonedStart = new Node(originalNode->val);
        cloneMap[originalNode] = clonedStart;

        // BFS queue
        queue<Node*> processingQueue;
        processingQueue.push(originalNode);

        while (!processingQueue.empty()) {
            Node* currOriginal = processingQueue.front();
            processingQueue.pop();
            
            Node* currClone = cloneMap[currOriginal];

            // Iterate over all neighbors
            for (auto& neighbor : currOriginal->neighbors) {
                // If not cloned yet
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    Node* newClone = new Node(neighbor->val);
                    cloneMap[neighbor] = newClone;
                    processingQueue.push(neighbor);
                }
                // Add to the cloned node's neighbors list
                currClone->neighbors.push_back(cloneMap[neighbor]);
            }
        }

        return clonedStart;
    }

    // Function to clone a given structure (Graph, Tree, Linked List)
    Node* cloneStructure(Node* root, bool useDFS = true) {
        cloneMap.clear(); // Reset mapping for each call
        return useDFS ? cloneDFS(root) : cloneBFS(root);
    }
};

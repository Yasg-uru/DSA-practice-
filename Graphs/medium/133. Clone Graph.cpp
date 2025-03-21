/*
Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
        // HashMap to store original node → cloned node mapping
        unordered_map<Node*, Node*> clonedNodes;
    
        // Helper function to perform DFS traversal and clone the graph
        void cloneGraphDFS(Node* clonedNode, Node* originalNode) {
            for (auto& neighbor : originalNode->neighbors) {
                // If neighbor has not been cloned yet
                if (clonedNodes.find(neighbor) == clonedNodes.end()) {
                    // Create a clone of the neighbor
                    Node* newNeighborClone = new Node(neighbor->val);
                    clonedNodes[neighbor] = newNeighborClone;
                    
                    // Add cloned neighbor to the cloned node's neighbors list
                    clonedNode->neighbors.push_back(newNeighborClone);
                    
                    // Recursively clone the neighbor’s connections
                    cloneGraphDFS(newNeighborClone, neighbor);
                } else {
                    // If already cloned, directly add the existing clone to neighbors
                    clonedNode->neighbors.push_back(clonedNodes[neighbor]);
                }
            }
        }
    
        // Main function to clone the graph
        Node* cloneGraph(Node* originalNode) {
            if (originalNode == nullptr) {
                return nullptr;
            }
    
            // Create the clone of the starting node
            Node* clonedNode = new Node(originalNode->val);
            
            // Store the mapping of original node to cloned node
            clonedNodes[originalNode] = clonedNode;
            
            // Perform DFS to clone the entire graph
            cloneGraphDFS(clonedNode, originalNode);
            
            return clonedNode;
        }
    };
    








// time complexity : o(v+e)
// space complexity : o(v) // for storing the nodes in the map 

// with BFS traversal
class Solution {
    public:
        // HashMap to store mapping between original nodes and their clones
        unordered_map<Node*, Node*> clonedNodesMap;
    
        // BFS function to clone the graph
        void cloneGraphBFS(queue<Node*>& processingQueue) {
            while (!processingQueue.empty()) {
                // Get the current node from the queue
                Node* originalNode = processingQueue.front();
                processingQueue.pop();
    
                // Get its corresponding cloned node
                Node* clonedNode = clonedNodesMap[originalNode];
    
                // Traverse all neighbors of the original node
                for (auto& neighbor : originalNode->neighbors) {
                    // If the neighbor is not yet cloned
                    if (clonedNodesMap.find(neighbor) == clonedNodesMap.end()) {
                        // Create a clone of the neighbor
                        Node* newNeighborClone = new Node(neighbor->val);
                        clonedNodesMap[neighbor] = newNeighborClone;
    
                        // Add the newly cloned neighbor to the cloned node's neighbors list
                        clonedNode->neighbors.push_back(newNeighborClone);
    
                        // Add the original neighbor to the queue for further processing
                        processingQueue.push(neighbor);
                    } else {
                        // If already cloned, simply add the existing clone to the neighbors list
                        clonedNode->neighbors.push_back(clonedNodesMap[neighbor]);
                    }
                }
            }
        }
    
        // Main function to clone the graph using BFS
        Node* cloneGraph(Node* originalNode) {
            if (originalNode == nullptr) {
                return nullptr;
            }
    
            // Clear previous mapping if any
            clonedNodesMap.clear();
    
            // Create a clone of the first node
            Node* clonedStartNode = new Node(originalNode->val);
            clonedNodesMap[originalNode] = clonedStartNode;
    
            // BFS queue initialization
            queue<Node*> processingQueue;
            processingQueue.push(originalNode);
    
            // Perform BFS to clone the entire graph
            cloneGraphBFS(processingQueue);
    
            return clonedStartNode;
        }
    };
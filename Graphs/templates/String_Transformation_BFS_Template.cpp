## String Transformation BFS Template 🚀
This repository includes a **String Transformation BFS Template**, useful for problems like:
- **Word Ladder**
- **Minimum Genetic Mutation**
- **Open the Lock**
- **General String Transformation Problems**

### How to Use the Template?
1. Copy `String_Transformation_BFS_Template.cpp` into your solution file.
2. Modify the `characters` parameter based on the allowed character set.
3. Use BFS to find the shortest transformation sequence.

📌 Check out the problems inside **`Graphs/BFS/`** for example implementations.

class Solution {
    public:
        int minTransformations(string start, string target, vector<string>& bank, string characters) {
            unordered_set<string> bankSet(bank.begin(), bank.end());
            queue<string> q;
            unordered_set<string> visited;
    
            // Initialize BFS
            visited.insert(start);
            q.push(start);
            int steps = 0;
    
            while (!q.empty()) {
                int n = q.size();
                while (n--) {
                    string curr = q.front();
                    q.pop();
    
                    // If we reached the target, return steps taken
                    if (curr == target) {
                        return steps;
                    }
    
                    // Explore all possible transformations
                    for (char ch : characters) { // Try all allowed character changes
                        for (int i = 0; i < curr.size(); i++) {
                            string neighbor = curr;
                            neighbor[i] = ch; // Change character at index i
    
                            // If the transformation is valid and not visited yet
                            if (visited.find(neighbor) == visited.end() && bankSet.find(neighbor) != bankSet.end()) {
                                visited.insert(neighbor);
                                q.push(neighbor);
                            }
                        }
                    }
                }
                steps++; // Increment step count after processing a level
            }
    
            return -1; // Transformation not possible
        }
    };
    
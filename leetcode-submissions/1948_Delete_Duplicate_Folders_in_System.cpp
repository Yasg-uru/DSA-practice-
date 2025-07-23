#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

class Node {
public:
    std::map<std::string, Node*> subdirs;
    bool isDeleted = false;

    Node() = default;
    ~Node() {
        for (auto& item : subdirs) {
            delete item.second;
        }
    }
};

class Solution {
public:
    std::vector<std::vector<std::string>> deleteDuplicateFolder(
        std::vector<std::vector<std::string>>& folderPaths) {

        Node* rootDir = new Node();

        // Build the directory tree
        for (const auto& folderPath : folderPaths) {
            Node* current = rootDir;
            for (const std::string& dir : folderPath) {
                if (current->subdirs.find(dir) == current->subdirs.end()) {
                    current->subdirs[dir] = new Node();
                }
                current = current->subdirs[dir];
            }
        }

        // Serialize subtrees and map identical structures
        std::unordered_map<std::string, std::vector<Node*>> encodingMap;
        encode(rootDir, encodingMap);

        // Mark duplicates for deletion
        for (const auto& pair : encodingMap) {
            if (pair.second.size() > 1) {
                for (Node* dup : pair.second) {
                    dup->isDeleted = true;
                }
            }
        }

        // Gather all valid paths
        std::vector<std::vector<std::string>> resultPaths;
        std::vector<std::string> tempPath;
        collect(rootDir, tempPath, resultPaths);

        delete rootDir;
        return resultPaths;
    }

private:
    std::string encode(Node* dir, std::unordered_map<std::string, std::vector<Node*>>& encodingMap) {
        if (dir->subdirs.empty()) return "()";

        std::vector<std::string> encodedParts;
        for (const auto& sub : dir->subdirs) {
            std::string encodedChild = encode(sub.second, encodingMap);
            encodedParts.push_back(sub.first + encodedChild);
        }
        std::sort(encodedParts.begin(), encodedParts.end());

        std::string signature = "(";
        for (const std::string& part : encodedParts) {
            signature += part;
        }
        signature += ")";

        encodingMap[signature].push_back(dir);
        return signature;
    }

    void collect(Node* dir, std::vector<std::string>& currentPath,
                 std::vector<std::vector<std::string>>& output) {
        for (const auto& sub : dir->subdirs) {
            if (sub.second->isDeleted) continue;
            currentPath.push_back(sub.first);
            output.push_back(currentPath);
            collect(sub.second, currentPath, output);
            currentPath.pop_back();
        }
    }
};

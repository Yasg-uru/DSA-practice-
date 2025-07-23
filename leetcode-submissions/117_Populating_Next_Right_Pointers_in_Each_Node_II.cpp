/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         if(not root)return root;
        queue<Node*>q;
        q.push(root);
        while(not q.empty()){
            vector<Node*>temp;
            int size = q.size();
            while(size--){
                Node* currNode = q.front();
                temp.push_back(currNode);

                q.pop();
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            for(int i=0;i<temp.size()-1;i++){
                temp[i]->next=temp[i+1];
            }
        }
        return root;
    }
};
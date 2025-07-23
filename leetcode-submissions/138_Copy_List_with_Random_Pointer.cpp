/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //i am solving this question by using the hasmap 
        unordered_map<Node*,Node*>mp;
        Node* temp=head;
        while(temp){
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node* currNode=mp[temp];
            currNode->next=mp[temp->next];
            currNode->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
};
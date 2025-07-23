/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void postorder(Node* root,vector<int>&ans){
    //base case
    if(root==NULL){
        return ;
    }
    //now going to each child of the root
    for(Node* child:root->children){
        postorder(child,ans);
    } 
    //after going to null or means all the childs of the root is traversed then we need to store the root in the ans array
    ans.push_back(root->val); 

}
    vector<int> postorder(Node* root) {
        //now i am using the dfs approach that can able to solve this question easily
vector<int>ans;
postorder(root,ans);
return ans;
    }
};
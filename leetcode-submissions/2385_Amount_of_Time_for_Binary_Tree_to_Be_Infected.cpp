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
 int 
class Solution {
public:
int calculatetime(treenode* startnode,unoredered_map<treenode*,treenode*>parent){
    unordered_set<treenode*>infected;
    int time=0;
    queue<node*>q;
    q.push(startnode);
    while(not q.empty()){
        int currsize=q.size();
        while(currsize--){
            treenode* currnode=q.front();
            bool infectedflag=false;
            q.pop();
            if(currnode->left and !infected.count(currnode->left)){
                infectedflag=true;
                infected.insert(currnode->left);
                q.push(currnode->left);
            }
            if(currnode->right and !infected.count(currnode->right)){
                infectedflag=true;
                infected.insert(currnode->right);
                q.push(currnode->right);
            }
            if(parent[currnode] and !infected.count(parent[currnode])){
                infectedflag=true;
                infected.insert(currnode->right);
                q.push(currnode->right);
            }
            if(infectedflag){
                time++;
            }
        }
    }
    return time;
}

treenode*  makeparent(treenode* root,int start,unordered_map<treenode*,treenode*>parent){
    queue<treenode*>q;
    q.push(root);
    treenode* startnode;
    while(!q.empty()){
        int currentsize=q.size();
        while(currsize--){
            node* currentnode=q.front();
            q.pop();
            //checking if current node is equal to start node
            if(currentnode->val==start){
                startnode=currentnode;
            } 
            if(currentnode->left!=NULL){
                parent[currentnode->left]=currentnode;
                q.push(currentnode->left);
            }
            if(currentnode->right!=NULL){
                parent[currentnode->right]=currentnode;
                q.push(currentnode->right);
            }

        }

    }
    return startnode;
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<treenode*,treenode*>parent;
        treenode* stratnode=makeparent(root,start,parent);
        return calculatetime(startnode,parent);
    }
};
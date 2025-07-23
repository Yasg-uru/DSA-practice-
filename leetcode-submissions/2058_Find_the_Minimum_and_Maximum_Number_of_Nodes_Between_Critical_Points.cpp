/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //in this i want to code this with using the previous and current ptr 
        
        ListNode* prev=head;
        ListNode* currnode=head->next;
        vector<int>indexarr;
        int index=1;
        while(currnode and  currnode->next){
            if(prev and currnode->next){
if((prev->val<currnode->val and currnode->val>currnode->next->val) or (prev->val>currnode->val and currnode->val<currnode->next->val)){
indexarr.push_back(index);
}
            }
index++;
prev=currnode;
currnode=currnode->next;

        }
        if(indexarr.size()<2){
            return {-1,-1};
        }
        int maxvalue=indexarr.back()-indexarr.front();
        int mini=INT_MAX;
        for(int i=0;i<indexarr.size()-1;i++){
            mini=min(mini,indexarr[i+1]-indexarr[i]);
        }
        return {mini,maxvalue};
    }
};
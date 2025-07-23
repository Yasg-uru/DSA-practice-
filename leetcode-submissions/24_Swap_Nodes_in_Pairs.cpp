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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL ){
            return head;
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* ans=head->next;
        while(1){
            prev->next=curr->next;
            curr->next=prev;
            ListNode* temp=prev->next;
            if(temp==NULL){
                break;
            }
            curr=temp->next;
            if(curr==NULL){
                break;
            }
            prev->next=curr;
            prev=temp;
        }
        return ans;

    }
};
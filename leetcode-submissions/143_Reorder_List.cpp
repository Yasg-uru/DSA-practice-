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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //now slow is at the mid point we need to beak th e list
        ListNode* prev=slow;
        ListNode* curr=slow->next;
        slow->next=NULL;
        while(curr!=NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode* ptr1=head;
        ListNode* ptr2=prev;
        while(ptr1 !=ptr2){
            ListNode* temp=ptr1->next;
            ptr1=ptr2;
            ptr2=temp;

        }
    }
};
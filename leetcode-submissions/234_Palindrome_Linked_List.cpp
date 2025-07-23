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
    bool isPalindrome(ListNode* head) {
        if(head==NULL ){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=slow->next;
        }
        //now slow is at thr mid point we need to reverse one half of the list
        ListNode* prev=slow;
        ListNode* curr=slow->next;
        while(curr!=NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode* ptr2=prev;
        ListNode* ptr1=head;
        while(ptr1!=ptr2){
            if(ptr1->val!=ptr2->val){
                return false;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
    }
};
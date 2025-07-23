/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * pos=new ListNode(-1);
        if(head==NULL or head->next==NULL){
            return pos;
        }
      ListNode * slow=head;
      ListNode * fast=head->next;
      while(fast and fast->next){
          if(slow==fast){
              break;
          }
          slow=slow->next;
          fast=slow->next;
      }  
      fast=head;
      int p=0;
      while(fast->next!=slow){
          p++;
          fast=fast->next;
      }
      ListNode * i=new ListNode(p);
      return i;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
       ListNode * ptr=head;
       while(ptr){
           if(ptr->next->val==val){
               ListNode * temp=ptr->next;
               ptr->next=ptr->next->next;
               free(temp);
               
           }
       } 
       return head;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
       ListNode* dummy1=new ListNode(-1);
       ListNode* p=dummy1;
       ListNode* dummy2=new ListNode(-1);
       ListNode* q=dummy2;
       ListNode* s=head;
       while( s!=NULL){
           if(s->val<x){
               dummy1->next=s;
               dummy1=dummy1->next;

           }else{
               dummy2->next=s;
               dummy2=dummy2->next;
           }
           s=s->next;
       } 
       dummy2->next=NULL;
       dummy1->next=q->next;
       return p->next;
    }
};
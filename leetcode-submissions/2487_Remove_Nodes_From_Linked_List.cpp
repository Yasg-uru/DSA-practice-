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
ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* nxt=NULL;
    while(curr){
    nxt=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nxt;
    }
    return prev;
}
     
    ListNode* removeNodes(ListNode* head) {
       /* if(head==NULL or head->next==NULL) return head;
      ListNode* temp=head;
      deque<ListNode*>dq;
      ListNode* temp2=new ListNode(-1);
      ListNode* head2=temp2;
      ListNode* temp3=head;
      bool flag=false;
      while(temp3){
          if(temp3->val==temp3->next->val){
              flag=true;
          }else{
              flag=false;
          }
      }
      while(temp!=NULL) {
          if(not dq.empty() and dq.back()->val<temp->val){
            temp2->next=temp;
            temp2=temp2->next;
              dq.pop_back();

          }
          dq.push_back(temp);
          temp=temp->next;
      } 
      temp2->next=NULL;
      
      if(flag==true){
          return head;
      }else{
          return head2->next;
      }*/
             head=reverse(head);
            ListNode* temp=head;
            while(temp and temp->next){
                if(temp->val>temp->next->val){
                    temp->next=temp->next->next;
                }else{
                    temp=temp->next;
                }
            }
            head=reverse(head);
            return head;
      
    }
};
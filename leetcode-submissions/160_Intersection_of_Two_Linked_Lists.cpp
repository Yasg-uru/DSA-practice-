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
int getlength(ListNode* head){
    ListNode* temp=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}
ListNode* movebyk(ListNode* head,int k){
    
    while(k--){
        head=head->next;

    }
    return head;

}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         int length1,length2;
         length1=getlength(headA);
         length2=getlength(headB);
         
             ListNode* ptr1=headA;
             ListNode* ptr2=headB;
         if(length1>length2){
             int k=length1-length2;
             ptr1=movebyk(ptr1,k);
         }else{
            int k=length2-length1;
             ptr2=movebyk(ptr2,k); 
         }
         while(ptr1!=NULL and ptr2!=NULL){
             if(ptr1==ptr2){
                 return ptr1;
             }
             ptr1=ptr1->next;
             ptr2=ptr2->next;
         }
         return NULL;

    }
};
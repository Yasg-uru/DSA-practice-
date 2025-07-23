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
    ListNode* reverseList(ListNode* ptr){
        ListNode* currPtr=ptr;
        ListNode* nextPtr=nullptr;
        ListNode* prevPtr=nullptr;
        while(currPtr){
            nextPtr=currPtr->next;
            currPtr->next=prevPtr;
            prevPtr=currPtr;
            currPtr=nextPtr;

        }
        return prevPtr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(!head || left==right){
        return head;
       }
       ListNode* ptr=head;
      for(int i=1;i<left-1;i++){
        ptr=ptr->next;

      }
      ListNode* ptr2=head;
      for(int i=1;i<right;i++){
ptr2=ptr2->next;
      }
      ListNode* nextOfRight=ptr2->next;
      ptr2->next=NULL;
      ListNode* newNode=reverseList(ptr->next);
      ptr->next=newNode;
      ListNode* lastNode=newNode;
      while(lastNode->next){
        lastNode=lastNode->next;
      }
lastNode->next=nextOfRight;
return head;



    }
};
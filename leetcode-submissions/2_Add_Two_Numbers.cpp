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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      //first we need to make dummy node for storing the answer 
      ListNode* dummynode=new ListNode(-1);
      ListNode* tail=dummynode;
      int carry=0;
      while(l1 || l2 || carry!=0){
          // if l1 not null then digit =0
          int digit1=l1!=NULL?l1->val:0;
          int digit2=l2!=NULL?l2->val:0;
          //now calculating the sum of the two digits with carry
          int sum=digit1+digit2+carry;
          //now calculating digit
          int digit=sum%10;
          carry=sum/10;
          //now we need to make a node
          ListNode* newnode=new ListNode(digit);
          tail->next=newnode;
          tail=tail->next;
          if(l1){
              l1=l1->next;
          }
          if(l2){
              l2=l2->next;
          }
      }
      return dummynode->next;
    }
};
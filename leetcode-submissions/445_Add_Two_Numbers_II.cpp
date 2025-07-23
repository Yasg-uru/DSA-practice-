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
        stack<int>st1, st2;
        ListNode* ptr1 = l1 ;
        ListNode* ptr2= l2;
        while(ptr1){
            st1.push(ptr1->val);
            ptr1=ptr1->next;

        }
        while(ptr2){
            st2.push(ptr2->val);
            ptr2=ptr2->next;

        }
        int carry = 0;
        ListNode* head = NULL;

        while(not st1.empty() or not st2.empty()){
            int val1 = st1.empty()?0 : st1.top();
            if(not st1.empty()){
                st1.pop();
            }
            int val2= st2.empty()?0 :st2.top();
            if(not st2.empty()){
                st2.pop();
            }
            int sum = val1+val2+carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            newNode->next = head;
            head= newNode;

        }
        if(carry>0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head; 
            head= newNode;

        }
        return head;
        
    }
};
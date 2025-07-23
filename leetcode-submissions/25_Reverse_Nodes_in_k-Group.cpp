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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        int count=0;
        ListNode* curr=head;
        while(curr!=NULL and count!=k){
            count++;
            curr=curr->next;
        }
        if(count==k){
            curr=reverseKGroup(curr,k);
              while (count-- > 0) {
            ListNode* nextNode = head->next;
            head->next = curr;
            curr = head;
            head = nextNode;
        }
        head=curr;
        }
        return head;
    }
};
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddptr=head;
        ListNode* evenptr=head->next;
        while(oddptr->next){
            oddptr->next=oddptr->next->next;
            evenptr->next=evenptr->next->next;
            oddptr=oddptr->next;
            evenptr=evenptr->next;
        }
        oddptr->next=evenptr;
        return head;
    }
};
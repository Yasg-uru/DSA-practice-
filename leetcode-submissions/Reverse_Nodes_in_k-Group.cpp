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
       
        ListNode* ptr = head;
        int count = 0 ;
        while(ptr){
            ptr = ptr->next ;
            count++;
        }
        if(count<k){
            return head ;
        }
        count =0 ;
        ListNode* prev = NULL ;
        ListNode* curr = head;
        ListNode* next = NULL ;
        while(curr  and count<k){
            count++;
            next = curr->next ;
            curr->next = prev ;
            prev = curr;
            curr = next;
        }
        if(count<k){
            return head ;
        }
        if(next!=NULL){
            head->next = reverseKGroup(next , k);
        }
        return prev ;
    }
};
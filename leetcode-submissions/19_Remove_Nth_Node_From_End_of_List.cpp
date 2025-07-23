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
int getlength(ListNode* head){
    ListNode* temp=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //now we need to find the length of the list
        int length=getlength(head);
        length=length-n;
        int i=1;
        ListNode* temp=head;
        while(i<=length){
            temp=temp->next;
            i++;
        }
        ListNode* temp2=temp->next;
        temp->next=temp->next->next;
        //temp2->next=NULL;
        free(temp2);
        return head;
    }

};
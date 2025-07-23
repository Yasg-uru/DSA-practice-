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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
     //in this code we have a simple  approach
     ListNode* temp1=list1;
     ListNode* prev=list1;
     ListNode* curr=list1;
     a--;
     while(temp1!=nullptr and a--){
        temp1=temp1->next;
        prev=temp1;
     }
     temp1=list1;
     while(temp1!=NULL and b--){
        temp1=temp1->next;
        curr=temp1;
     }
     ListNode* temp2=list2;
     while(temp2->next!=NULL){
        temp2=temp2->next;
     }
     prev->next=list2;
     temp2->next=curr->next;
     return list1;
    }
};
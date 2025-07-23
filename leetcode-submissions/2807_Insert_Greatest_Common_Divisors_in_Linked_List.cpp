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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        ListNode* ptr=head;
        ListNode* nextptr=NULL;
        while(ptr->next ){
int newdigit=gcd(ptr->val,ptr->next->val);
ListNode* newNode=new ListNode(newdigit);
nextptr=ptr->next;
ptr->next=newNode;
newNode->next=nextptr;
ptr=nextptr;

        }
        return head;
    }
};
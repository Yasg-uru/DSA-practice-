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
    int getLength(ListNode* ptr){
        int l =0 ;
        while(ptr) {ptr = ptr->next;  l++;}
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(not head) return head ;
        ListNode* ptr = head;
        ListNode* temp1 , *temp2;
        int index =0 ;
        int length = getLength(head);
        while(ptr ){
            if(index==(k-1)){
                temp1= ptr;
                
            }
            if(index==(length-k)){
                temp2 = ptr;
            }
            ptr = ptr->next;
            index++;
        }
        swap(temp1->val , temp2->val);
        return head ;
        
    }
};
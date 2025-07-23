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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int ans=0;
        if(head==NULL or (head->val==0 and head->next==NULL)){
            return ans;
            
        }
        int pd=1;
        while(temp){
           int t=temp->val;
           ans+=t*pd;
            pd*=2;
            temp=temp->next;
        }
        return ans;
    }
};
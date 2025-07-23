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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //we need to create a set of an array
        set<int>st(nums.begin(),nums.end());
        ListNode* temp=head;
         while(temp){
            while(st.count(temp->val)){
                temp->val=temp->next->val;
                temp->next=temp->next->next?temp->next->next:NULL;
            }
            temp=temp->next;

         }
        return head;
    }
};
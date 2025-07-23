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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>lists;
        ListNode* temp = head;
        while(temp){
            lists.push_back(temp->val);
            temp= temp->next;
        }
        stack<int>st;
        vector<int>ans(lists.size(),0);
        for(int i=0;i<lists.size();i++){
            while(not st.empty() and lists[st.top()]<=lists[i]){
                ans[st.top()]= lists[i];
                st.pop();
            }
            st.push(i);
        }
        return ans ;
    }
};
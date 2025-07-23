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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>lookup(nums.begin(), nums.end());
        ListNode* ptr = head;
        int components = 0 ;
        bool isConnected = false;

        while(ptr){
            if(lookup.count(ptr->val)){
                if(not isConnected){
                    components++;
                }
                isConnected= true ;
            }else {
                isConnected = false;
            }
            ptr = ptr->next;
        }
        return components ;
        
    }
};
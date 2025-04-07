class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            int len = 1;
            ListNode* odd = new ListNode(-1);
            ListNode* ptr = odd;
            ListNode* even = new ListNode(-1);
            ListNode* ptr1 = even;
            while(head != NULL){
                if(len %2 != 0){
                    ptr->next = head;
                    ptr = ptr->next;
                    head = head->next;
                    len++;
                }
                else {
                    ptr1->next = head;
                    ptr1 = ptr1->next;
                    head = head->next;
                    len++;
                }
            }
            ptr1->next = NULL;
            ptr1 = ptr1->next;
            ptr->next = even->next;
    
            return odd->next;
    
        }
    };
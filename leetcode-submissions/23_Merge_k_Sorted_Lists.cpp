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
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

         if(list1==NULL){
             return list2;
         }
         if(list2==NULL){
             return list1;
         }
        ListNode* ptr1=list1;
        ListNode*  ptr2=list2;
          ListNode* ptr=ptr1;
          if(ptr1->val>ptr2->val){
              ptr=ptr2;
              ptr2=ptr2->next;
          }else{
              ptr=ptr1;
              ptr1=ptr1->next;
          }
          ListNode* ptr3=ptr;
        while(ptr1!=NULL and ptr2!=NULL){
            if(ptr1->val<ptr2->val){
                 
                ptr3->next=ptr1;
                ptr1=ptr1->next;
                
            }else{
                
                ptr3->next=ptr2;
                ptr2=ptr2->next;
                

            }
            ptr3=ptr3->next;
        }
        if(ptr1==NULL){
            ptr3->next=ptr2;
        }else{
             ptr3->next=ptr1;
        }
       
       return ptr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
         while(lists.size()>1){

         ListNode*  mergedhead=mergeTwoLists(lists[0],lists[1]);
         lists.push_back(mergedhead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
        
        }
        return lists[0];
         
       
        
    }
};
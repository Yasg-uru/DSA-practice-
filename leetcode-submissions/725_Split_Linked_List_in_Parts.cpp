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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int n=0;
        while(curr!=NULL){
            n++;
            curr=curr->next;

        }

        int size=n/k;
        int rem=n%k;
       vector<ListNode*>res(k,nullptr);
       
        curr=head;
        for(int i=0;i<k;i++){
            ListNode* part=curr;
            int resize=size;
            if(rem>0){
                rem--;
                resize++;

            }
            for(int j=0;j<(resize-1) and curr!=NULL;j++){
             
                curr=curr->next;
            }
            if(curr!=NULL){
                ListNode* nextptr=curr->next;
                curr->next=NULL;
                curr=nextptr;
            }
            res[i]=part;
        }
        return res;
    }
};
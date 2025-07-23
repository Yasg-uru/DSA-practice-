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
ListNode* reverseList(ListNode* head){
    ListNode* prev=nullptr,*curr=head,*nextptr=nullptr;
    while(curr){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;

}
void insert(ListNode* &head,int digit){
    ListNode* newnode=new ListNode(digit);
    if(head==nullptr){
         head=newnode;
    }else{
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;

        }
        temp->next=newnode;
    }
}
    ListNode* doubleIt(ListNode* head) {
        //i have simple approach to solve this question by uisng the adding the value sof the linked list twice and then creating the list from it
        ListNode* ptr=head;
        int sum =0;
string sums="";

        while(ptr){
sums.push_back(ptr->val+'0');
ptr=ptr->next;
        }
        sum=stoi(sums);
        sum=sum+sum;
        ListNode* newhead=NULL;
cout<<"this is a sum :"<<sum;
        while(sum>0){
            int digit=sum%10;
            insert(newhead,digit);
            sum/=10;

        }
         newhead=reverseList(newhead);

        return newhead;

    }
};
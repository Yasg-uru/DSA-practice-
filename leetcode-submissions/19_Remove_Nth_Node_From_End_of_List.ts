/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    //now solving this question by using the the two pointer approach that can solve this question in easy way 
    if(head===null || head->next===null){
        return null;
    }
let i:number=0;
let ptr:ListNode=head;

while(i<n){
    if(ptr===null){
        return null;
    }
ptr=ptr.next;
i++;
}
//after that we need to check whether ptr is null or not if null then return head->next
if(ptr===null){
    return head.next;
}
let ptr2:ListNode=head;
while(ptr.next!==null){
    ptr=ptr.next;
    ptr2=ptr2.next;
}
ptr2.next=ptr2.next.next;

};
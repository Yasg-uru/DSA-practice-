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

function reverseList(head: ListNode | null): ListNode | null {
    let prev :ListNode|null = null, curr:ListNode |null= head;
    if(!head || !head.next){
        return head;
    }
    while(curr){
        const nextPtr:ListNode|null = curr.next;
        curr.next= prev;
        prev=curr;
        curr= nextPtr;
    }
    return prev;
};
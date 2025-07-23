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

function deleteMiddle(head: ListNode | null): ListNode | null {
    let index:number =0;
    if(!head) return head;
    let ptr:ListNode | null =head;
    let length:number =0;
    while(ptr){
        length++;
        ptr=ptr.next;
    }
    //after finding the length finding the middle of the list 
    let middleIndex:number =Math.floor(length/2);
    ptr=head;
    while(ptr && index!=(middleIndex-1)){
        ptr=ptr.next;
        index++;
    }
    ptr.next=ptr.next.next;
    return head;
};
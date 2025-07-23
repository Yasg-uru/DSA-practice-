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

function rotateRight(head: ListNode | null, k: number): ListNode | null {
    if(!head || !head.next){
        return head;
    }
    let length:number =0;
    let ptr:ListNode | null =head;
    while(ptr){
        length++;
        ptr=ptr.next;
    }
    k=k%length;
    //after this 
    let IndexJustBeforeRotationStart:number =length-k-1;
    ptr=head;
    let index :number=0;
    while(index <IndexJustBeforeRotationStart){
        ptr=ptr.next;
        index++;
    }
    // we are on the index before 
    let newHead:ListNode | null =ptr.next;
    let temp:ListNode | null=ptr.next;
    ptr.next=null;
    while(temp.next){
        temp=temp.next;
    }
    temp.next=head;
    return newHead;

};
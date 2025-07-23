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

function swapNodes(head: ListNode | null, k: number): ListNode | null {
    let length:number =0;
    if(!head) return head;
    let ptr:ListNode | null =head;
    while(ptr){
        ptr=ptr.next;
        length++;
    }
    //after this 
    let index:number =1;
    let startIndex=k;
    let endIndex=length-k+1;
    let startNode :ListNode | null =null;
    let endNode :ListNode | null =null;
    //after that 
    ptr=head;
    while(ptr){
if(index===startIndex){
startNode =ptr;
}
if(index===endIndex){
    endNode =ptr;
}
index++;
ptr=ptr.next;
    }
    let tempNode :number =startNode.val ;
    startNode.val =endNode.val ;
    endNode.val=tempNode ;
    return head;
};
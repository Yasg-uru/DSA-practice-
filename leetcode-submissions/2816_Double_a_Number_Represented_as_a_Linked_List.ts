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

function doubleIt(head: ListNode | null): ListNode | null {
    let num:string="";
    let temp:ListNode | null =head;
    while(temp){
        num+=temp.val.toString();
        temp=temp.next;
    }
    let actualSum:string  =(parseInt(num)+parseInt(num)).toString();
    let dummyNode :ListNode | null =new ListNode(-1);
    temp=dummyNode;
    for( const n of actualSum){
temp.next=new ListNode(parseInt(n));
temp=temp.next;
    }
return dummyNode.next;

};
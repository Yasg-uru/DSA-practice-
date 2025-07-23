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

function mergeInBetween(list1: ListNode | null, a: number, b: number, list2: ListNode | null): ListNode | null {
// we need to find the ath node and also the bth node and we need to insert the second list in the gap of the a andb and then return the answer
if(!list2) return list1 ;
let tempNode :ListNode | null =list1;
let athNode :ListNode | null =null;
let bthNode :ListNode | null =null;


let index:number =0;
while(tempNode){
    if(index==a-1){
        athNode=tempNode ;
    }
    if(index==b){
        bthNode=tempNode.next;

    }
    tempNode=tempNode.next;
    index++;
}
let list2End:ListNode | null =list2;
while(list2End.next){
    list2End=list2End.next;
}
if(athNode && bthNode){
    athNode.next=list2;
    if(list2End){
        list2End.next=bthNode;
    }
}
return list1;

};
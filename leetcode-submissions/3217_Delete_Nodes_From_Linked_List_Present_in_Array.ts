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

function modifiedList(nums: number[], head: ListNode | null): ListNode | null {
    if(!head) return head;
    if(nums.length===0) return head;
    let temp:ListNode | null=head;
    const set:Set<number>=new Set(nums);// for lookup in order of 1 time 
    const array:number[]=[];
    while(temp){
        if(!set.has(temp.val)){
            array.push(temp.val);
        }
        temp=temp.next;
    }
    let dummyNode:ListNode | null =new ListNode(-1);
    temp=dummyNode;
   for(let i:number=0;i<array.length;i++){
    temp.next=new ListNode(array[i]);
    temp=temp.next;
   }
   return dummyNode.next;
        
    
};
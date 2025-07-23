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

function numComponents(head: ListNode | null, nums: number[]): number {
    // we need to store the values of the nums in the set to lookup in constant time and then we need to check in the linked list values if the consecutive is occurs the store it into the connected component 
    const set:Set<number>=new Set(nums);
    let ptr:ListNode | null =head;
    let components :number =0;
    let isConnnected :boolean =false;
    while(ptr){
        // we need to lookup and check 
    if(set.has(ptr.val)){
        if(!isConnnected){
            components++;
        }
        isConnnected=true;
    }else{
        isConnnected =false;
    }
        ptr=ptr.next;

    }
    return components ;
};
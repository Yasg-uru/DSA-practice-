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

function nextLargerNodes(head: ListNode | null): number[] {
    // we need to use the stack to solve this question 
    const stack:number[]=[];
    let vals :number[]=[];
    let ptr:ListNode | null =head;
    while(ptr){
        vals.push(ptr.val);
        ptr=ptr.next;

    }
    const result:number[]=Array.from({length:vals.length},()=>0);
    for(let i:number =0;i<vals.length;i++){
        while(stack.length>0 && vals[stack[stack.length-1]]<vals[i]){
         
                let index :number =stack.pop()!;
                result[index]=vals[i];

              

          
        }
            stack.push(i);
        
    }
   return result;
};
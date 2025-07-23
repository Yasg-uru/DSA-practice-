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

function spiralMatrix(m: number, n: number, head: ListNode | null): number[][] {
    let left :number =0,right:number =n-1,top:number =0,down:number =m-1;
    let ptr:ListNode | null =head;
    let direction :number =0;
    const matrix:number[][]=Array.from({length:m},()=>Array.from({length:n},()=>-1));

    while(left<=right && top<=down && ptr){
        if(direction===0){
            // row is  stable but the columns will change 
            for(let col:number =left;col<=right;col++){
                if(!ptr) return matrix;
                matrix[top][col]=ptr.val;
                ptr=ptr.next;
            }
            top++;

        }else if(direction===1){
            for(let row:number =top;row<=down;row++){
                if(!ptr) return matrix;
                matrix[row][right]=ptr.val;
                ptr=ptr.next;
            }
            right--;
        }else if(direction===2){
            for(let col:number =right;col>=left;col--){
                if(!ptr) return matrix;
                matrix[down][col]=ptr.val;
                ptr=ptr.next;
            }
            down--;
        }
        else if(direction===3){
            for(let row:number =down;row>=top;row--){
                if(!ptr) return matrix;
                matrix[row][left]=ptr.val;
                ptr=ptr.next;
            }
            left++;
        }
        direction=(direction+1)%4;
    }
    return matrix;

};
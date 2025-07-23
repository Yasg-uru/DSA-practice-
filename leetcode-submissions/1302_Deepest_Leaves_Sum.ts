/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function deepestLeavesSum(root: TreeNode | null): number {
    if(!root) return 0;
    const q:Array<TreeNode|null>=[root];
    const ans:number[][]=[];
    while(q.length>0){
let size:number =q.length;
const temp:number[]=[];
while(size--){
    const currNode:TreeNode|null=q.shift()!;
    temp.push(currNode.val);
    if(currNode.left){
        q.push(currNode.left);
    }
    if(currNode.right){
        q.push(currNode.right);
    }
}
ans.push(temp);
    }
    let sum:number =0;
    for(let i=0;i<ans[ans.length-1].length;i++){
sum+=ans[ans.length-1][i];
    }
    return sum ;
};
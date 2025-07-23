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

function sumOfLeftLeaves(root: TreeNode | null): number {
    const sum : number[]= new Array(1).fill(0);
    solve(root , sum);
    return sum[0];
};
function  solve(root :TreeNode | null , sum:number[]):void{
    if(!root){
        return ;
    }
    if(root.left!==null && root.left.right===null && root.left.left===null){
        sum[0]+=root.left.val;
    }
solve(root.left, sum);
solve(root.right, sum);
}
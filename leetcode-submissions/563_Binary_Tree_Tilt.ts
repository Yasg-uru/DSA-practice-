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
function solve(root:TreeNode|null,res:number[]){
    if(!root) return 0 ;
  let left=   solve(root.left,res);
  let right= solve(root.right,res);
  res[0]+=Math.abs(left-right);
//   if(!root.left && !root.right) return 0;
  return root.val+left+right;
}
function findTilt(root: TreeNode | null): number {
    if(!root) return 0 ;
    const res:number[]=[0];

    solve(root,res);
    return res[0];
};
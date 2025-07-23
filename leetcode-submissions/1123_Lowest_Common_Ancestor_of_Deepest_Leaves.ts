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

function lcaDeepestLeaves(root: TreeNode | null): TreeNode | null {
    return solve(root)[0];
};
function solve(root:TreeNode | null):[TreeNode|null, number]{
    if(!root){
        return [null, 0];
    }
    const left:[TreeNode|null, number]= solve(root.left);
    const right:[TreeNode|null, number ]= solve(root.right);
    if(left[1]==right[1]){
        return [root, left[1]+1];
    }
    return left[1]>right[1]?[left[0], left[1]+1]:[right[0], right[1]+1];
}
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

function evaluateTree(root: TreeNode | null): boolean {
    if(!root.left && !root.right) return root.val===1;
    let left :boolean =evaluateTree(root.left);
    let right :boolean =evaluateTree(root.right);
    
    if(root.val===2){
        return left || right;
    }
    if(root.val===3){
        return left && right;
    }
    return false;
};
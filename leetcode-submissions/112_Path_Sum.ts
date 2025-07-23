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

function hasPathSum(root: TreeNode | null, targetSum: number): boolean {

    if(!root) return false;
    const queue:[(TreeNode | null),number][] =[[root,root.val]];
    while(queue.length){
        let currSize:number = queue.length;
        while(currSize--){
            const [currNode,currSum]=queue.shift()!;
            if(currSum===targetSum) return true ;
            if(currNode.left){
                queue.push([currNode.left,currSum+currNode.left.val]);
            }
            if(currNode.right){
                queue.push([currNode.right,currSum+currNode.right.val]);
            }
        }
    }
    return false;

};
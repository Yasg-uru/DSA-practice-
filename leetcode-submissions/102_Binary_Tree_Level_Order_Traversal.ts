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

function levelOrder(root: TreeNode | null): number[][] {
    if(! root){
        return [];
    }
    const queue:TreeNode[]= [root];
    const ans:number[][]= [];
    while(queue.length>0){
        let size = queue.length;
        const level:number[]= [];
        while(size--){
            const currNode:TreeNode = queue[0];
            level.push(currNode.val);
            queue.shift();
            if(currNode.left){
                queue.push(currNode.left);
            }
            if(currNode.right){
                queue.push(currNode.right);
            }
            
        }
        ans.push(level);
        
    }
    return ans ;
};
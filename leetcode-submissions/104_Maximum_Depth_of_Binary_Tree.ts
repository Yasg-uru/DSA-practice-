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

function maxDepth(root: TreeNode | null): number {
    if(!root)return 0 ;
    const q:Array<TreeNode|null> =[root];
    let levels :number =0;

    while(q.length>0){
        let size:number =q.length;
        while(size--){
            const currNode:TreeNode| null =q.shift()!;
            if(currNode.right){
                q.push(currNode.right);
            }
            if(currNode.left){
                q.push(currNode.left);
            }
        }
        levels++;

    }
    return levels ;

};
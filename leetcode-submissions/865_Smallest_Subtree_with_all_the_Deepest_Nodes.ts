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

function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
    return solve(root)[0];
};
function solve(root : TreeNode|null):[TreeNode|null , number]{
    if(!root) {
        return [null , 0 ];
    }
    const [leftNode , leftHeight]= solve(root.left);
    const [rightNode , rightHeight ]= solve(root.right);
    if(leftHeight===rightHeight){
        return [root, leftHeight+1];
    }else if(leftHeight>rightHeight){
        return [leftNode , leftHeight+1];
    }else{
        return [rightNode , rightHeight+1 ];
    }
}
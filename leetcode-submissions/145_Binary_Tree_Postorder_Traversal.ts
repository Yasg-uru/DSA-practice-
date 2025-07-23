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
 
function postorder(root:TreeNode | null):void{
    if(root===null){
        return;
    }
    postorder(root.left);
    postorder(root.right);
    ans.push(root.val);

}
function postorderTraversal(root: TreeNode | null): number[] {
    postorder(root);
    return ans;
};
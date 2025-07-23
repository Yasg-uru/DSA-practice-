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
function inorder(root:TreeNode | null ,ans:number[]):void{
    if(!root){return ;}
    inorder(root.left,ans);
    ans.push(root.val);
    inorder(root.right,ans);


}
function isValidBST(root: TreeNode | null): boolean {
    const ans:number[]=[];
    inorder(root,ans);
    for(let i:number =1;i<ans.length;i++){
        if(ans[i]<ans[i-1]){
            return false;
        }
    }
    return true ;
};
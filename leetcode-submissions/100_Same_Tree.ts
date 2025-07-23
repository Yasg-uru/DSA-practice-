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

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    if(p && !q)return false;
    if(q && !p) return false;
    const qu1:Array<TreeNode | null > =[p], qu2:Array<TreeNode | null> =[q];
    while(qu1.length>0 && qu2.length>0){
        let size1:number = qu1.length;
        let size2:number = qu2.length;
        if(size1!==size2) return false;
        while(size1-- && size2--){
            const curr1:TreeNode | null = qu1.shift()!;
            const curr2:TreeNode | null = qu2.shift()!;
            if(!curr1|| !curr2) return curr1===curr2 ;
            if(curr1.val!==curr2.val){
                return false;
            }
            if( curr1.left || curr2.left ){
                if(!curr1.left || !curr2.left) return false;
                qu1.push(curr1.left);
                qu2.push(curr2.left);

            }
            if( curr1.right ||  curr2.right ){
                if(!curr1.right || !curr2.right) return false;
                qu1.push(curr1.right);
                qu2.push(curr2.right);

            }

        }
    }
    return qu1.length===qu2.length ;


};
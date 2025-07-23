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

function createBinaryTree(descriptions: number[][]): TreeNode | null {
    let mp=new Map<number,TreeNode>();
    let children=new Set<number>();
    for(const arr of descriptions){
        let parent=arr[0],child=arr[1],isLeft=arr[2];
        children.add(child);
        if(!mp.has(parent)){
            const parentNode=new TreeNode(parent);

            mp.set(parent,parentNode);
        }
        if(!mp.has(child)){
            const childNode=new TreeNode(child);
            mp.set(child,childNode);
        }
        if(isLeft==1){
            mp.get(parent).left=mp.get(child);
        }else{
            mp.get(parent).right=mp.get(child);
        }
    }
let node=-1;
    for(const arr of descriptions){
        if(!children.has(arr[0])){
            node=arr[0];
            break;
        }
    }
return mp.get(node);
};
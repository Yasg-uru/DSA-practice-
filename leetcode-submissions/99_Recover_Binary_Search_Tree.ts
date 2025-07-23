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

/**
 Do not return anything, modify root in-place instead.
 */
 function inorder(
    root: TreeNode | null,
    prev: { node: TreeNode | null },
    first: { node: TreeNode | null },
    middle: { node: TreeNode | null },
    last: { node: TreeNode | null }
): void {
    if (!root) return;

    inorder(root.left, prev, first, middle, last);

    
    if (prev.node && prev.node.val > root.val) {
        if (!first.node) {
            first.node = prev.node;
            middle.node = root;
        } else {
            last.node = root;
        }
    }
    prev.node = root; 

    inorder(root.right, prev, first, middle, last);
}

function recoverTree(root: TreeNode | null): void {
    let prev = { node: new TreeNode(Number.MIN_SAFE_INTEGER) };
    let first = { node: null as TreeNode | null };
    let middle = { node: null as TreeNode | null };
    let last = { node: null as TreeNode | null };

    inorder(root, prev, first, middle, last);

    
    if (first.node && last.node) {
        [first.node.val, last.node.val] = [last.node.val, first.node.val];
    } else if (first.node && middle.node) {
        [first.node.val, middle.node.val] = [middle.node.val, first.node.val];
    }
}
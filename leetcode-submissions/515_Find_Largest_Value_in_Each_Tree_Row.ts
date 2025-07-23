function largestValues(root: TreeNode | null): number[] {
    if (root === null) return []; // If the tree is empty, return an empty array

    const queue: TreeNode[] = [root]; // Initialize the queue with the root node
    const ans: number[] = []; // To store the largest values

    while (queue.length > 0) {
        let currSize: number = queue.length;
        const temp: number[] = []; // To store values at the current level

        while (currSize-- > 0) {
            const CurrNode = queue.shift(); // Remove the node from the queue

            if (CurrNode) { // Ensure the node is not null
                temp.push(CurrNode.val); // Push the value of the current node
                if (CurrNode.left) {
                    queue.push(CurrNode.left); // Add left child to the queue
                }
                if (CurrNode.right) {
                    queue.push(CurrNode.right); // Add right child to the queue
                }
            }
        }
        ans.push(Math.max(...temp)); // Add the largest value at the current level
    }

    return ans;
}

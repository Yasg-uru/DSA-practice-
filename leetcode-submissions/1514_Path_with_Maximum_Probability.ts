function maxProbability(n: number, edges: number[][], succProb: number[], start_node: number, end_node: number): number {
    // Correct the declaration of adj array
    const adj: Array<[number, number][]> = Array.from({ length: n }, () => []);

    // Build the adjacency list
    for (let i = 0; i < edges.length; i++) {
        adj[edges[i][0]].push([edges[i][1], succProb[i]]);
        adj[edges[i][1]].push([edges[i][0], succProb[i]]);
    }

    // Initialize the probability array
    const prob: number[] = Array.from({ length: n }, () => 0.0);
    prob[start_node] = 1.0;

    // Create a queue for BFS (or modified BFS)
    const queue: [number, number][] = [];
    queue.push([start_node, 1.0]);

    while (queue.length !== 0) {
        // Dequeue the front element
        const [currentNode, currentProb] = queue.shift()!;

        // Traverse all neighbors
        for (let [neighbourNode, neighbourProb] of adj[currentNode]) {
            // Check if this path offers a higher probability
            if (prob[neighbourNode] < currentProb * neighbourProb) {
                prob[neighbourNode] = currentProb * neighbourProb;
                queue.push([neighbourNode, prob[neighbourNode]]);
            }
        }
    }

    return prob[end_node];
}

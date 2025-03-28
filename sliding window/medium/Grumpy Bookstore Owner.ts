function maxSatisfied(customers: number[], grumpy: number[], minutes: number): number {
    let j: number = 0, maxUnsatisfaction: number = 0;
    let current: number = 0;
    const n: number = customers.length;
    
    // Compute initial unsatisfied customers for the first 'minutes' window
    for (j = 0; j < minutes; j++) {
        current += (customers[j] * grumpy[j]); // Only count if grumpy[j] is 1
    }
    maxUnsatisfaction = current;
    
    // Sliding window to find max unsatisfied customers we can convert
    while (j < n) {
        current += (customers[j] * grumpy[j]); // Add new element
        current -= (customers[j - minutes] * grumpy[j - minutes]); // Remove old element
        maxUnsatisfaction = Math.max(maxUnsatisfaction, current);
        j++;
    }
    
    // Compute already satisfied customers when grumpy[i] is 0
    let alreadySatisfied: number = 0;
    for (let i: number = 0; i < n; i++) {
        if (grumpy[i] === 0) {
            alreadySatisfied += customers[i];
        }
    }
    
    return alreadySatisfied + maxUnsatisfaction;
}

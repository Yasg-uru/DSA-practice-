function findChampion(n: number, edges: number[][]): number {
    // we need to create a indegree array to store the indegree of the nodes 
    const indegree:number[]=Array.from({length:n},()=>0);
    for(const edge of edges ){
        indegree[edge[1]]++;

    }
    let count :number =0;
    let ans:number =0;
    for(let i=0;i<n;i++){
        if(indegree[i]==0){
            count ++;
            ans=i;
        }
    }
    return count >1?-1:ans;
};
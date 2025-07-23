function shortestDistanceAfterQueries(n: number, queries: number[][]): number[] {
    // now we need to create a none adjacency matrix 
    let adj:{[key:number]:number[]}={};
    for(let i:number=0;i<n-1;i++){
        adj[i]=[];

    }
    for(let i:number=0;i<n-1;i++){
        adj[i].push(i+1);

    }
    const result:number[]=[];
    for(const query of queries){
        const [u,v]=query;
        //after this we need to insert this in adjacency list 
        adj[u].push(v);
        let d:number =bfs(n,adj);
        result.push(d);

    }
    return result ;
};
function bfs(n:number ,adj:{[key:number]:number[]}){
    const q:number[]=[0];
    const visited:boolean[]=Array.from({length:n},()=>false);
    visited[0]=true ;

    let level=0;

    while(q.length>0){
        let currSize=q.length;
        while(currSize--){
            let node=q[0];
            q.shift();
            if(node==n-1){
                return level;
            }
            for(const nbr of adj[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        level++;

    }
    return -1;
}
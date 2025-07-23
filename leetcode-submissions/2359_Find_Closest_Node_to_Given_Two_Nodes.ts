function closestMeetingNode(edges: number[], node1: number, node2: number): number {
    const adj:Map<number , number[]>= new Map();
    const n :number = edges.length;
    for(let i:number=0;i<n;i++){
        if(edges[i]==-1) continue;
        if(!adj.has(i)) adj.set(i ,[]);
        adj.get(i).push(edges[i]);
        
    }
    const distFromNode1:number[] = new Array(n).fill(Number.MAX_SAFE_INTEGER);
    const distFromNode2:number[] = new Array(n ).fill(Number.MAX_SAFE_INTEGER);
    const visited1:boolean[]= new Array(n).fill(false), visited2:boolean[]= new Array(n).fill(false);
    DFS(node1 , distFromNode1, adj , 0 ,visited1 );
    DFS(node2 , distFromNode2 , adj , 0  ,visited2);
    let minDistanceNode = -1, minDistance = Number.MAX_SAFE_INTEGER;
    for(let i :number =0 ;i<n;i++){
        const maxDistance = Math.max(distFromNode1[i], distFromNode2[i]);
        if(maxDistance<minDistance){
            minDistance = maxDistance ;
            minDistanceNode = i ;
        }
    }
    return minDistanceNode ;
};
function DFS(currNode :number , dist:number[], adj:Map<number , number[]>,currStep : number , visited:boolean[]):void{
    visited[currNode] = true ;
    dist[currNode]= currStep;
    if(!adj.has(currNode)) return ;
    for(const nbr of adj.get(currNode)!){
        if(!visited[nbr]){
            DFS(nbr , dist, adj , currStep+1, visited);
        }
    }
}
class DSU{
    parent:number[];
    rank:number[];

    constructor(size:number){
        this.parent=new Array(size).fill(0).map((_,index)=>index);
        this.rank=new Array(size).fill(0);
    }
    find(x:number):number{
    return this.parent[x]===x?x:this.find(this.parent[x]);
    }
    union(u:number ,v:number):void{
        let parentU:number =this.find(u);
        let parentV:number =this.find(v);
        if(parentU===parentV){return ;}
        if(parentU>=parentV){
            this.parent[parentV]=parentU;
            this.rank[parentU]++;
        }else{
            this.parent[parentU]=parentV;
            this.rank[parentV]++;
        }

    }
}
function findCircleNum(isConnected: number[][]): number {
    const dsu=new DSU(isConnected.length);
    for(let i:number=0;i<isConnected.length;i++){
        for(let j:number =0;j<isConnected[0].length;j++){
            if(isConnected[i][j]===1){
                dsu.union(i,j);
            }
        }
    }
    let cc:number =0;
    for(let i:number =0;i<isConnected.length;i++){
        if(dsu.find(i)===i){
            cc++;
        }
    }
    return cc;
};
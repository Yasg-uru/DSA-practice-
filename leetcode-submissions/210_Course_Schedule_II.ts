function findOrder(numCourses: number, prerequisites: number[][]): number[] {
    const queue:number[]=[];

    const indegree:number[]=new Array(numCourses).fill(0);
    const adj:Map<number,number[]>=new Map();
    const result :number[] =[];
    for(const [course,preq] of prerequisites){
        if(!adj.has(preq)) adj.set(preq,[]);
        adj.get(preq)!.push(course);
        indegree[course]++;
    }
    //after this will need to insert the zero indegree nodes to the queue 
    for(let i:number =0;i<numCourses;i++){
        if(indegree[i]===0){
            queue.push(i);
        }
    }
    while(queue.length>0){
        //extracting the node
        const course:number = queue.shift();
        result.push(course);

        if(adj.has(course)){
            for(const nbr of adj.get(course)){
            indegree[nbr]--;
            if(indegree[nbr]===0){

            queue.push(nbr);
            }
            }
        }
    }
    return result;

};
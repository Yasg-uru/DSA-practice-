function maxCandies(status: number[], candies: number[], keys: number[][], containedBoxes: number[][], initialBoxes: number[]): number {
    const foundBoxes:Set<number>= new Set();
    const n :number = candies.length;
    const visited :boolean[]= new Array(n).fill(false);
    let collectedCandies :number =0 ;
    for(const box of initialBoxes){
        collectedCandies+=dfs(box , status , candies , keys , containedBoxes , initialBoxes, visited , foundBoxes);
    }
    return collectedCandies ;
};
function dfs(box :number , status: number[], candies: number[], keys: number[][], containedBoxes: number[][], initialBoxes: number[],visited :boolean[], foundBoxes:Set<number> ):number{
    if(visited[box]===true){
        return 0 ;

    }
    if(status[box]===0){
        foundBoxes.add(box);//abhi philal toh status false hai but kya pata kabhi key mil jaye toh open ho jaye
        return 0 ;

    }
    let collectedCandies:number =candies[box];
    visited[box]= true ;
    // ab kya collected boxes me boxes milenge 
    for(const insideBox  of containedBoxes[box]){
        collectedCandies+=dfs(insideBox, status , candies , keys , containedBoxes , initialBoxes, visited , foundBoxes);
    }
    //ab kya keys mil sakte hai 
    for(const key of keys[box]){
        status[key]= 1 ;
        if(foundBoxes.has(key)){
            collectedCandies+=dfs(key, status , candies , keys , containedBoxes , initialBoxes, visited , foundBoxes);
        }
    }
    return collectedCandies ;
}
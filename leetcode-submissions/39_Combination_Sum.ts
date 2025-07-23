function combinationSum(candidates: number[], target: number): number[][] {
    const result:number[][]= [];
    const temp : number[]= [];
    
    function backTrack(currSum:number , start:number):void{
        const n = candidates.length;
        if(currSum===target){
            result.push([...temp]);
            return ;
        }
        if(start>candidates.length || currSum>target){
            return ;
        }

        for(let i:number = start ;i<n;i++){
            temp.push(candidates[i]);
            backTrack(currSum+candidates[i], i);
            temp.pop();
        }
        
    }
        backTrack(0 , 0 );
        return result ;

};
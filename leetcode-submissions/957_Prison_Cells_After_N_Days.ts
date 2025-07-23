function prisonAfterNDays(cells: number[], n: number): number[] {
    while(n--){
        const temp = Array.from({length:cells.length},()=>0);
        for(let i:number  =1;i<=6;i++){
            if(cells[i-1]==cells[i+1]){
                temp[i]=1;
                
            }else{
                temp[i]=0;
            }
            
        }
        cells = temp;
    }
    return cells ;
};
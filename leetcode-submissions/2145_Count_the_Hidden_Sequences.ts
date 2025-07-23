function numberOfArrays(differences: number[], lower: number, upper: number): number {
    let maxVal :number=0 , minVal :number =0 , curr:number =0 ;
    for(const diff of differences){
        curr = diff+curr;
        maxVal = Math.max(maxVal , curr);
        minVal = Math.min(minVal , curr);
        if((upper-maxVal)-(lower-minVal)+1<=0){
            return 0 ;
        }
    } 
        return (upper-maxVal)-(lower-minVal)+1;
};